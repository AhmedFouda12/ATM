#include "ATM/ATM.h"
#include "Interface/UserInterface.h"

int main()
{
    // Initialize and run the ATM
    ATM *atm = ATM::getInstance();
    atm->run();
    return 0;
}