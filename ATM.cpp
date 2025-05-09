#include "ATM.h"
#include "UserInterface.h"
#include "AdminMode.h"
#include "CustomerMode.h"
#include "Customer.h"
#include <iostream>

using namespace std;

ATM *ATM::instance = nullptr;

ATM::ATM()
    : currentMode(""), currentUser(nullptr), adminPassword("admin"), nextAccountID(1), nextTransactionID(1) {}

ATM *ATM::getInstance()
{
    if (!instance)
        instance = new ATM();
    return instance;
}

void ATM::run()
{
    while (true)
    {
        UserInterface::clearScreen();
        UserInterface::displayWelcomeScreen();
        UserInterface::displayMainMenu();
        int choice = UserInterface::getIntInput();
        if (choice == 1)
            handleAdminMode();
        else if (choice == 2)
            handleCustomerMode();
        else if (choice == 0)
            break;
    }
}

void ATM::displayMainMenu()
{
    UserInterface::displayMainMenu();
    int choice = UserInterface::getIntInput();
    switch (choice)
    {
    case 1:
        handleAdminMode();
        break;
    case 2:
        handleCustomerMode();
        break;
    case 0:
        exit(0);
    default:
        UserInterface::showMessage("Invalid choice");
    }
}

void ATM::handleAdminMode()
{
    UserInterface::clearScreen();
    UserInterface::showMessage("Enter admin password:");
    string pw = UserInterface::getInput();
    if (!authenticateAdmin(pw))
    {
        UserInterface::showMessage("Invalid password.");
        UserInterface::getInput();
        return;
    }
    while (true)
    {
        UserInterface::clearScreen();
        UserInterface::displayAdminMenu();
        int choice = UserInterface::getIntInput();
        if (choice == 1)
            addAccount();
        else if (choice == 2)
            deleteAccount();
        else if (choice == 3)
        {
            for (auto acc : accounts)
                displayAccountDetails(acc);
        }
        else if (choice == 0)
            break;
        UserInterface::getInput();
    }
}

void ATM::handleCustomerMode()
{
    UserInterface::clearScreen();
    UserInterface::showMessage("Enter userID:");
    string uid = UserInterface::getInput();
    UserInterface::showMessage("Enter password:");
    string pw = UserInterface::getInput();
    if (!authenticateCustomer(uid, pw))
    {
        UserInterface::showMessage("Login failed.");
        UserInterface::getInput();
        return;
    }
    while (true)
    {
        UserInterface::clearScreen();
        UserInterface::displayCustomerMenu();
        int choice = UserInterface::getIntInput();
        if (choice == 1)
        {
            UserInterface::displayCheckingMenu();
            int op = UserInterface::getIntInput();
            if (op == 1)
            {
                double amt = UserInterface::getDoubleInput();
                deposit(currentUser, amt);
            }
            else if (op == 2)
            {
                double amt = UserInterface::getDoubleInput();
                withdraw(currentUser, amt);
            }
            else if (op == 3)
            {
                UserInterface::showMessage("Enter target userID:");
                string tu = UserInterface::getInput();
                Account *to = nullptr;
                for (auto a : accounts)
                    if (a->getUserID() == tu)
                        to = a;
                double amt = UserInterface::getDoubleInput();
                if (to)
                    transfer(currentUser, to, amt);
            }
            else if (op == 4)
            {
                checkBalance(currentUser);
            }
            else if (op == 5)
                changePassword(currentUser);
        }
        else if (choice == 2)
        {
            UserInterface::displaySavingsMenu();
            int op = UserInterface::getIntInput();
            if (op == 1)
            {
                double amt = UserInterface::getDoubleInput();
                deposit(currentUser, amt);
            }
            else if (choice == 2)
            {
                checkBalance(currentUser);
            }
            else if (op == 3)
                changePassword(currentUser);
        }

        else if (choice == 0)
            break;
        UserInterface::getInput();
    }
}

bool ATM::authenticateAdmin(string pw)
{
    return pw == adminPassword;
}

bool ATM::authenticateCustomer(string userID, string pw)
{
    for (auto acc : accounts)
    {
        if (acc->getUserID() == userID && acc->validatePassword(pw))
        {
            currentUser = acc;
            return true;
        }
    }
    return false;
}

void ATM::addAccount()
{
    UserInterface::showMessage("Enter new userID:");
    string uid = UserInterface::getInput();
    UserInterface::showMessage("Enter password:");
    string pw = UserInterface::getInput();
    UserInterface::showMessage("Enter initial balance:");
    double bal = UserInterface::getDoubleInput();
    Account *acc = new CheckingAccount(nextAccountID++, uid, pw, bal);
    accounts.push_back(acc);
    UserInterface::showMessage("Account created.");
}

void ATM::deleteAccount()
{
    UserInterface::showMessage("Enter accountID to delete:");
    int id = UserInterface::getIntInput();
    for (auto it = accounts.begin(); it != accounts.end(); ++it)
    {
        if ((*it)->getAccountID() == id)
        {
            delete *it;
            accounts.erase(it);
            UserInterface::showMessage("Account deleted.");
            return;
        }
    }
    UserInterface::showMessage("Account not found.");
}

void ATM::deposit(Account *acc, double amount)
{
    if (acc->deposit(amount))
    {
        logTransaction("Deposit", amount, acc->getAccountID());
        UserInterface::showMessage("Deposit successful.");
    }
    else
        UserInterface::showMessage("Deposit failed.");
}

void ATM::withdraw(Account *acc, double amount)
{
    if (acc->withdraw(amount))
    {
        logTransaction("Withdraw", amount, acc->getAccountID());
        UserInterface::showMessage("Withdraw successful.");
    }
    else
        UserInterface::showMessage("Insufficient funds.");
}

void ATM::transfer(Account *from, Account *to, double amount)
{
    if (dynamic_cast<CheckingAccount *>(from)->transfer(to, amount))
    {
        logTransaction("Transfer", amount, from->getAccountID());
        UserInterface::showMessage("Transfer successful.");
    }
    else
        UserInterface::showMessage("Transfer failed.");
}

void ATM::changePassword(Account *acc)
{
    UserInterface::showMessage("Enter new password:");
    string np = UserInterface::getInput();
    if (dynamic_cast<CheckingAccount *>(acc)->changePassword(np))
        UserInterface::showMessage("Password changed.");
}
void ATM::checkBalance(Account *acc)
{
    UserInterface::showMessage("Current balance: " + to_string(acc->getBalance()));
}

void ATM::displayAccountDetails(Account *acc)
{
    cout << "ID: " << acc->getAccountID()
         << " | UserID: " << acc->getUserID()
         << " | Balance: " << acc->getBalance() << endl;
    UserInterface::getInput();
}

void ATM::logTransaction(string type, double amount, int accountID)
{
    Transaction *t = new Transaction(nextTransactionID++, type, amount, accountID);
    transactions.push_back(t);
    t->logTransaction();
}