#pragma once
#include <string>
#include <ctime>
using namespace std;

class Transaction {
public:
    Transaction(int id, string type, double amount, int accountID)
      : transactionID(id), type(type), amount(amount), timestamp(time(nullptr)), accountID(accountID) {}
    virtual ~Transaction() = default;

    void logTransaction() const;
    int getTransactionID() const;
    string getType() const;
    double getAmount() const;
    time_t getTimestamp() const;
    int getAccountID() const;

protected:
    int transactionID;
    string type;
    double amount;
    time_t timestamp;
    int accountID;
};

class DepositTransaction : public Transaction {
public:
    DepositTransaction(int id, double amount, int accountID)
      : Transaction(id, "Deposit", amount, accountID) {}
};

class WithdrawTransaction : public Transaction {
public:
    WithdrawTransaction(int id, double amount, int accountID)
      : Transaction(id, "Withdraw", amount, accountID) {}
};

class TransferTransaction : public Transaction {
public:
    TransferTransaction(int id, double amount, int fromAccountID, int toAccountID)
      : Transaction(id, "Transfer", amount, fromAccountID), targetAccountID(toAccountID) {}
    int getTargetAccountID() const;
private:
    int targetAccountID;
};
