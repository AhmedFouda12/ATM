#include "Transaction.h"
#include <iostream>
using namespace std;

void Transaction::logTransaction() const {
    cout << "[Transaction] ID=" << transactionID
         << ", Type=" << type
         << ", Amount=" << amount
         << ", Timestamp=" << timestamp
         << ", AccountID=" << accountID
         << endl;
}

int Transaction::getTransactionID() const { return transactionID; }
string Transaction::getType() const { return type; }
double Transaction::getAmount() const { return amount; }
time_t Transaction::getTimestamp() const { return timestamp; }
int Transaction::getAccountID() const { return accountID; }

int TransferTransaction::getTargetAccountID() const { return targetAccountID; }