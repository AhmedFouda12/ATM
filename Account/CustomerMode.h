#pragma once
#include <string>
using namespace std;   
class ATM;
class Account;

class CustomerMode {
private:
    Account* currentAccount;
    int wrongAttempts;
public:
    CustomerMode();
    bool authenticate(const string &userID, const string &password, ATM* atm);
    void selectAccount(ATM* atm);
    void performCheckingOperations(ATM* atm);
    void performSavingsOperations(ATM* atm);
    void deposit(ATM* atm, double amount);
    void withdraw(ATM* atm, double amount);
    void transfer(ATM* atm, Account* to, double amount);
    void changePassword(ATM* atm, const string &newPw);
    void checkBalance(ATM* atm);
    void resetWrongAttempts();
    int incrementWrongAttempts();
};