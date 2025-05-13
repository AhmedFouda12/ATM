#include "UserInterface.h"
#include <iostream>
using namespace std;

void UserInterface::displayWelcomeScreen() {
    cout << "Welcome to the ATM System" << endl;
}

void UserInterface::displayMainMenu() {
    cout << "1) Admin Mode\n2) Customer Mode\n0) Exit" << endl;
}

void UserInterface::displayAdminMenu() {
    cout << "--- Admin Menu ---\n1) Add Account\n2) Delete Account\n3) View All Accounts\n0) Back" << endl;
}

void UserInterface::displayCustomerMenu() {
    cout << "--- Customer Menu ---\n1) Checking\n2) Savings\n0) Back" << endl;
}

void UserInterface::displayAccountSelection() {
    cout << "Select account by ID:" << endl;
}

void UserInterface::displayCheckingMenu() {
    cout << "--- Checking Menu ---\n1) Deposit\n2) Withdraw\n3) Transfer\n4) Check Balance\n5) Change Password\n0) Back" << endl;
}

void UserInterface::displaySavingsMenu() {
    cout << "--- Savings Menu ---\n1) Deposit\n2) Check Balance\n3) Change Password\n0) Back" << endl;
}

string UserInterface::getInput() {
    string input;
    getline(cin, input);
    return input;
}

int UserInterface::getIntInput() {
    int val; cin >> val; cin.ignore(); return val;
}

double UserInterface::getDoubleInput() {
    double val; cin >> val; cin.ignore(); return val;
}

void UserInterface::showMessage(const string &msg) {
    cout << msg << endl;
}

void UserInterface::clearScreen() {
    // simple clear for Windows
    system("cls");
}