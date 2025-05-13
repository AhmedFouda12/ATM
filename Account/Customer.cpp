#include "Customer.h"
using namespace std;

bool CheckingAccount::withdraw(double amount) {
    if (amount > 0 && amount <= balance) {
        balance -= amount;
        return true;
    }
    return false;
}

bool CheckingAccount::deposit(double amount) {
    if (amount > 0) {
        balance += amount;
        return true;
    }
    return false;
}

bool CheckingAccount::transfer(Account* to, double amount) {
    if (withdraw(amount)) {
        to->deposit(amount);
        return true;
    }
    return false;
}
bool CheckingAccount::checkBalance() const {
    return balance;
}

bool CheckingAccount::changePassword(const string &newPw) {
    password = newPw;
    return true;
}

bool SavingsAccount::deposit(double amount) {
    if (amount > 0) {
        balance += amount;
        return true;
    }
    return false;
}
bool SavingsAccount::checkBalance() const {
    return balance;
}