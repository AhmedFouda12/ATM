#pragma once
#include <string>


class UserInterface {
public:
    static void displayWelcomeScreen();
    static void displayMainMenu();
    static void displayAdminMenu();
    static void displayCustomerMenu();
    static void displayAccountSelection();
    static void displayCheckingMenu();
    static void displaySavingsMenu();
    static std::string getInput();
    static int getIntInput();
    static double getDoubleInput();
    static void showMessage(const std::string &);
    static void clearScreen();
};