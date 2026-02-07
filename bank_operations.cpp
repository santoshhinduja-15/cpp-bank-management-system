#include "bank_operations.h"
#include "account.h"
#include "file_manager.h"
#include <iostream>

using namespace std;

void createNewAccount() {
    Account acc;
    acc.createAccount();
    writeAccount(acc);
    cout << "\nAccount created successfully!\n";
}

void displayAllAccounts() {
    readAllAccounts();
}

void depositMoney() {
    int accNo;
    double amount;
    Account acc;

    cout << "Enter Account Number: ";
    cin >> accNo;

    if (!findAccount(accNo, acc)) {
        cout << "Account not found!\n";
        return;
    }

    cout << "Enter amount to deposit: ";
    cin >> amount;

    if (amount <= 0) {
        cout << "Error: Deposit amount must be greater than 0\n";
        return;
    }

    acc.deposit(amount);
    updateAccount(acc);   // (text file update, explained later)
    cout << "Amount deposited successfully!\n";
}

void withdrawMoney() {
    int accNo;
    double amount;
    Account acc;

    cout << "Enter Account Number: ";
    cin >> accNo;

    if (!findAccount(accNo, acc)) {
        cout << "Account not found!\n";
        return;
    }

    cout << "Enter amount to withdraw: ";
    cin >> amount;

    if (amount <= 0) {
        cout << "Error: Withdrawal amount must be greater than 0\n";
        return;
    }

    if (!acc.withdraw(amount)) {
        cout << "Insufficient balance!\n";
        return;
    }

    updateAccount(acc);
    cout << "Withdrawal successful!\n";
}
