#include "Account.h"
#ifndef DEBITACCOUNT_H
#define DEBITACCOUNT_H

class DebitAccount:public Account
{
public:
    void withdrawMoney(int nMoney);
    DebitAccount(int newCustomerId, int newMoney);
};

#endif