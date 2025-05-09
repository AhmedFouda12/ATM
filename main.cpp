#include "ATM.h"
#include "UserInterface.h"

int main() {
    // Initialize and run the ATM
    ATM* atm = ATM::getInstance();
    atm->run();
    return 0;
}