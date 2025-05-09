#include "AdminMode.h"
#include "ATM.h"
using namespace std;
string password = "admin123"; // Default password for admin mode

AdminMode::AdminMode(string pw)
    : password(pw), wrongAttempts(0) {}

bool AdminMode::authenticate(string input) {
    if (input == password) { resetWrongAttempts(); return true; }
    incrementWrongAttempts(); return false;
}

void AdminMode::addAccount(ATM* atm) {
    atm->addAccount();
}

void AdminMode::deleteAccount(ATM* atm) {
    atm->deleteAccount();
}

void AdminMode::viewAllAccounts(ATM* atm) {
    const auto& accts = atm->getAccounts();
    for (auto acc : accts) {
        atm->displayAccountDetails(acc);
    }
}

void AdminMode::resetWrongAttempts() {
    wrongAttempts = 3;
}

int AdminMode::incrementWrongAttempts() {
    return ++wrongAttempts;
}