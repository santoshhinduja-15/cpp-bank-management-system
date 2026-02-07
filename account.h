#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <iostream>
#include <string>
using namespace std;

class Account {
private:
    int accountNumber;
    string name;
    double balance;

public:
    void createAccount();
    void showAccount() const;

    int getAccountNumber() const;
    string getName() const;
    double getBalance() const;

    void deposit(double amount);
    bool withdraw(double amount);

    // For text file reading
    friend istream& operator>>(istream& in, Account& acc);
};

#endif
