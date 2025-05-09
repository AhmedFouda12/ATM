#pragma once
#include <string>
using namespace std;

class ATM;

class AdminMode {
private:
    string password;
    int wrongAttempts;
public:
    AdminMode(string pw);
    bool authenticate(string input);
    void addAccount(ATM* atm);
    void deleteAccount(ATM* atm);
    void viewAllAccounts(ATM* atm);
    void resetWrongAttempts();
    int incrementWrongAttempts();
};