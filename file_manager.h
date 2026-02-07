#ifndef FILE_MANAGER_H
#define FILE_MANAGER_H

#include "account.h"

void writeAccount(const Account& acc);
void readAllAccounts();
bool findAccount(int accNo, Account& acc);
void updateAccount(const Account& acc);

#endif
