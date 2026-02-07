#include "file_manager.h"
#include <fstream>
#include <iostream>
#include <cstdio>   // for remove, rename
using namespace std;


void writeAccount(const Account& acc) {
    ofstream outFile("accounts.txt", ios::app);

    if (!outFile) {
        cout << "Error opening file for writing!\n";
        return;
    }

    outFile << acc.getAccountNumber() << " "
            << acc.getName() << " "
            << acc.getBalance() << endl;

    outFile.close();
}

void readAllAccounts() {
    ifstream inFile("accounts.txt");

    if (!inFile) {
        cout << "No account data found!\n";
        return;
    }

    Account acc;

    while (inFile >> acc) {
        acc.showAccount();
        cout << "-----------------------\n";
    }

    inFile.close();
}

bool findAccount(int accNo, Account& acc) {
    ifstream inFile("accounts.txt");

    if (!inFile) {
        return false;
    }

    while (inFile >> acc) {
        if (acc.getAccountNumber() == accNo) {
            inFile.close();
            return true;
        }
    }

    inFile.close();
    return false;
}

void updateAccount(const Account& updatedAcc) {
    ifstream inFile("accounts.txt");
    ofstream tempFile("temp.txt");

    if (!inFile || !tempFile) {
        cout << "File error during update!\n";
        return;
    }

    Account acc;

    while (inFile >> acc) {
        if (acc.getAccountNumber() == updatedAcc.getAccountNumber()) {
            tempFile << updatedAcc.getAccountNumber() << " "
                     << updatedAcc.getName() << " "
                     << updatedAcc.getBalance() << endl;
        } else {
            tempFile << acc.getAccountNumber() << " "
                     << acc.getName() << " "
                     << acc.getBalance() << endl;
        }
    }

    inFile.close();
    tempFile.close();

    remove("accounts.txt");
    rename("temp.txt", "accounts.txt");
}
