#pragma once
#include "Account.h"
#include <string>
using namespace std;

// CheckingAccount implements Account interface
typedef Account BaseAccount; // alias for clarity

class CheckingAccount : public Account {
public:
    CheckingAccount(int id, const string &userID, const string &password, double balance)
        : Account(id, userID, password, balance) {}
    bool withdraw(double amount) override;
    bool deposit(double amount) override;
    bool transfer(Account* to, double amount);
    bool checkBalance() const;
    bool changePassword(const string &newPw);
};

class SavingsAccount : public Account {
public:
    SavingsAccount(int id, const string &userID, const string &password, double balance)
        : Account(id, userID, password, balance) {}
    bool checkBalance() const;
    bool deposit(double amount) override;

};