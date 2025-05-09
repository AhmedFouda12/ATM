#include "Account.h"
using namespace std;

Account::Account(int accountID, string userID, string password, double balance)
    : accountID(accountID), userID(userID), password(password), balance(balance), wrongPasswordAttempts(0) {}

Account::~Account() {}

int Account::getAccountID() const { return accountID; }
string Account::getUserID() const { return userID; }
bool Account::validatePassword(string pw) {
    if (pw == password) { resetWrongAttempts(); return true; }
    incrementWrongAttempts(); return false;
}
double Account::getBalance() const { return balance; }
void Account::resetWrongAttempts() { wrongPasswordAttempts = 0; }
int Account::incrementWrongAttempts() { return ++wrongPasswordAttempts; }