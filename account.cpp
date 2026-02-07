#include "account.h"

void Account::createAccount() {
    cout << "Enter Account Number: ";
    cin >> accountNumber;

    cout << "Enter Account Holder Name: ";
    cin >> name;

    cout << "Enter Initial Balance: ";
    cin >> balance;
}

void Account::showAccount() const {
    cout << "\nAccount Number: " << accountNumber;
    cout << "\nName: " << name;
    cout << "\nBalance: " << balance << endl;
}

int Account::getAccountNumber() const {
    return accountNumber;
}

string Account::getName() const {
    return name;
}

double Account::getBalance() const {
    return balance;
}

void Account::deposit(double amount) {
    balance += amount;
}

bool Account::withdraw(double amount) {
    if (amount > balance) {
        return false;
    }
    balance -= amount;
    return true;
}

// Operator overloading for reading from text file
istream& operator>>(istream& in, Account& acc) {
    in >> acc.accountNumber >> acc.name >> acc.balance;
    return in;
}
