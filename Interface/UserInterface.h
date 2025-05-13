#pragma once
#include <string>
using namespace std;


class UserInterface {
public:
    static void displayWelcomeScreen();
    static void displayMainMenu();
    static void displayAdminMenu();
    static void displayCustomerMenu();
    static void displayAccountSelection();
    static void displayCheckingMenu();
    static void displaySavingsMenu();
    static string getInput();
    static int getIntInput();
    static double getDoubleInput();
    static void showMessage(const string &);
    static void clearScreen();
};