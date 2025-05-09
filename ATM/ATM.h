#pragma once
#include <vector>
#include <string>
using namespace std;

#include "../Account/Account.h"
#include "../Trans/Transaction.h"

class AdminMode;
class CustomerMode;
class UserInterface;

class ATM
{
private:
    static ATM *instance;
    string currentMode;
    Account *currentUser;
    vector<Account *> accounts;
    vector<Transaction *> transactions;
    string adminPassword;
    int nextAccountID;
    int nextTransactionID;
    ATM();

public:
    static ATM *getInstance();
    void run();

    // expose accounts for admin and customer modes
    const std::vector<Account *> &getAccounts() const { return accounts; }

    // internal handlers
    void displayMainMenu();
    void handleAdminMode();
    void handleCustomerMode();
    bool authenticateAdmin(string pw);
    bool authenticateCustomer(string userID, string pw);
    void addAccount();
    void deleteAccount();
    void deposit(Account *acc, double amount);
    void withdraw(Account *acc, double amount);
    void transfer(Account *from, Account *to, double amount);
    void checkBalance(Account *acc);
    void changePassword(Account *acc);
    void displayAccountDetails(Account *acc);
    void logTransaction(string type, double amount, int accountID);
};