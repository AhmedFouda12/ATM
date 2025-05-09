#pragma once
#include <iostream>
#include <string>
using namespace std;

class Account {
public:
    Account(int accountID, string userID, string password, double balance);
    virtual ~Account();

    int getAccountID() const;
    string getUserID() const;
    bool validatePassword(string pw);
    double getBalance() const;
    void resetWrongAttempts();
    int incrementWrongAttempts();

    virtual bool withdraw(double amount) = 0;
    virtual bool deposit(double amount) = 0;

protected:
    int accountID;
    string userID;
    string password;
    double balance;
    int wrongPasswordAttempts;
};
