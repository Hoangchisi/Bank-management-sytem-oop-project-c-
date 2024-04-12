#include "Account.h"
#include <iostream>
int Account::countId = 0;
Account::Account()
{
    id = -1;
    customerId = -1;
    money = 0;
}

void Account::depositMoney(int nMoney)
{
    money += nMoney;
}

int Account::getId()
{
    return id;
}

int Account::getMoney()
{
    return money;
}