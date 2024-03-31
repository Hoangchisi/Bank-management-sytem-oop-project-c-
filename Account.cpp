#include "Account.h"
#include <iostream>
int Account::countId = 0;
Account::Account()
{
    id = countId++;
    customerId = 404;
    money = 0;
}

Account::Account(int newCustomerId, int newMoney)
{
    id = countId++;
    customerId = newCustomerId;
    money = newMoney;
}

void Account::depositMoney(int nMoney)
{
    money += nMoney;
}

void Account::withdrawMoney(int nMoney)
{
    money -= nMoney;
}

int Account::getId()
{
    return id;
}

int Account::getMoney()
{
    return money;
}