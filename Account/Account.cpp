#include "Account.h"
using namespace std;

Account::Account(int accountID, string userID, string password, double balance)
    : accountID(accountID), userID(userID), password(password), balance(balance), wrongPasswordAttempts(0) {}

Account::~Account() {}

int Account::getAccountID() const { return accountID; }
string Account::getUserID() const { return userID; }
bool Account::validatePassword(string pw)
{
    if (pw == password)
    {
        resetWrongAttempts();
        return true;
    }
    else if (wrongPasswordAttempts >= 3)
    {
        cout << "Account locked due to too many failed attempts." << endl;
        wrongPasswordAttempts++;
        return false;
    }
    else
    {
        cout << "Invalid password. Attempts left: " << (3 - incrementWrongAttempts()) << endl;
    }
    return false;
}
double Account::getBalance() const { return balance; }
void Account::resetWrongAttempts() { wrongPasswordAttempts = 0; }
int Account::incrementWrongAttempts() { return ++wrongPasswordAttempts; }