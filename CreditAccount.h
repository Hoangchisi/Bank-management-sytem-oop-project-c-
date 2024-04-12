#include "Account.h"
#ifndef CREDITACCOUNT_H
#define CREDITACCOUNT_H

class CreditAccount:public Account
{
public:
    void withdrawMoney(int nMoney);
    CreditAccount(int newCustomerId, int newMoney);
};

#endif