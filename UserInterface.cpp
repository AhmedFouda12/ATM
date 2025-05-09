#include "UserInterface.h"
#include <iostream>

void UserInterface::displayWelcomeScreen() {
    std::cout << "Welcome to the ATM System" << std::endl;
}

void UserInterface::displayMainMenu() {
    std::cout << "1) Admin Mode\n2) Customer Mode\n0) Exit" << std::endl;
}

void UserInterface::displayAdminMenu() {
    std::cout << "--- Admin Menu ---\n1) Add Account\n2) Delete Account\n3) View All Accounts\n0) Back" << std::endl;
}

void UserInterface::displayCustomerMenu() {
    std::cout << "--- Customer Menu ---\n1) Checking\n2) Savings\n0) Back" << std::endl;
}

void UserInterface::displayAccountSelection() {
    std::cout << "Select account by ID:" << std::endl;
}

void UserInterface::displayCheckingMenu() {
    std::cout << "--- Checking Menu ---\n1) Deposit\n2) Withdraw\n3) Transfer\n4) Check Balance\n5) Change Password\n0) Back" << std::endl;
}

void UserInterface::displaySavingsMenu() {
    std::cout << "--- Savings Menu ---\n1) Deposit\n2) Check Balance\n3) Change Password\n0) Back" << std::endl;
}

std::string UserInterface::getInput() {
    std::string input;
    std::getline(std::cin, input);
    return input;
}

int UserInterface::getIntInput() {
    int val; std::cin >> val; std::cin.ignore(); return val;
}

double UserInterface::getDoubleInput() {
    double val; std::cin >> val; std::cin.ignore(); return val;
}

void UserInterface::showMessage(const std::string &msg) {
    std::cout << msg << std::endl;
}

void UserInterface::clearScreen() {
    // simple clear for Windows
    std::system("cls");
}