#include "CustomerMode.h"
#include "../ATM/ATM.h"
#include "../Interface/UserInterface.h"

CustomerMode::CustomerMode()
    : currentAccount(nullptr), wrongAttempts(3) {}

bool CustomerMode::authenticate(const std::string &userID, const std::string &password, ATM *atm)
{
    const auto &accts = atm->getAccounts();
    for (auto acc : accts)
    {
        if (acc->getUserID() == userID && acc->validatePassword(password))
        {
            currentAccount = acc;
            resetWrongAttempts();
            return true;
        }
    }
    if (incrementWrongAttempts() >= 3)
        exit(0);
    return false;
}

void CustomerMode::selectAccount(ATM *atm)
{
    const auto &accts = atm->getAccounts();
    for (auto acc : accts)
    {
        atm->displayAccountDetails(acc);
    }
    UserInterface::displayAccountSelection();
    int id = UserInterface::getIntInput();
    for (auto acc : accts)
    {
        if (acc->getAccountID() == id)
        {
            currentAccount = acc;
            return;
        }
    }
    UserInterface::showMessage("Account not found.");
}

void CustomerMode::performCheckingOperations(ATM *atm)
{
    while (true)
    {
        UserInterface::clearScreen();
        UserInterface::displayCheckingMenu();
        int choice = UserInterface::getIntInput();
        if (choice == 1)
        {
            UserInterface::showMessage("Enter amount to deposit:");
            double amt = UserInterface::getDoubleInput();
            deposit(atm, amt);
        }
        else if (choice == 2)
        {
            UserInterface::showMessage("Enter amount to withdraw:");
            double amt = UserInterface::getDoubleInput();
            withdraw(atm, amt);
        }
        else if (choice == 3)
        {
            UserInterface::showMessage("Enter target account ID to transfer:");
            int tid = UserInterface::getIntInput();
            Account *to = nullptr;
            for (auto a : atm->getAccounts())
                if (a->getAccountID() == tid)
                    to = a;
            UserInterface::showMessage("Enter amount to transfer:");
            double amt = UserInterface::getDoubleInput();
            if (to)
                transfer(atm, to, amt);
            else
                UserInterface::showMessage("Target account not found.");
        }
        else if (choice == 4)
        {
            UserInterface::showMessage("Enter new password:");
            std::string npw = UserInterface::getInput();
            changePassword(atm, npw);
        }
        else if (choice == 0)
        {
            break;
        }
        else
            UserInterface::showMessage("Invalid choice.");
        UserInterface::getInput();
    }
}

void CustomerMode::performSavingsOperations(ATM *atm)
{
    while (true)
    {
        UserInterface::clearScreen();
        UserInterface::displaySavingsMenu();
        int choice = UserInterface::getIntInput();
        if (choice == 1)
        {
            UserInterface::showMessage("Enter amount to deposit:");
            double amt = UserInterface::getDoubleInput();
            deposit(atm, amt);
        }
        else if (choice == 2)
        {
            UserInterface::showMessage("Enter amount to withdraw:");
            double amt = UserInterface::getDoubleInput();
            withdraw(atm, amt);
        }
        else if (choice == 4)
        {
            UserInterface::showMessage("Enter new password:");
            std::string npw = UserInterface::getInput();
            changePassword(atm, npw);
        }
        else if (choice == 0)
        {
            break;
        }
        else
            UserInterface::showMessage("Invalid choice.");
        UserInterface::getInput();
    }
}

void CustomerMode::deposit(ATM *atm, double amount)
{
    atm->deposit(currentAccount, amount);
}

void CustomerMode::withdraw(ATM *atm, double amount)
{
    atm->withdraw(currentAccount, amount);
}

void CustomerMode::transfer(ATM *atm, Account *to, double amount)
{
    atm->transfer(currentAccount, to, amount);
}

void CustomerMode::changePassword(ATM *atm, const std::string &newPw)
{
    atm->changePassword(currentAccount);
}

void CustomerMode::checkBalance(ATM *atm)
{
    atm->displayAccountDetails(currentAccount);
}

void CustomerMode::resetWrongAttempts()
{
    wrongAttempts = 0;
}

int CustomerMode::incrementWrongAttempts()
{
    return ++wrongAttempts;
}