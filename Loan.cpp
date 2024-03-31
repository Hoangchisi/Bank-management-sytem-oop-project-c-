#include "Loan.h"

int Loan::countId = 0;

Loan::Loan()
{
    id = countId++;
    type = "Undefined";
    accountId = 404;
    customerId = 404;
    money = 0;
}

Loan::Loan(std::string newType, int newAccountId, int newCustomerId,int nMoney)
{
    id = countId++;
    type = newType;
    accountId = newAccountId;
    customerId = newCustomerId;
    money = nMoney;
}

void Loan::changeMoney(int nMoney)
{
    money += nMoney;
}

int Loan::getMoney()
{
    return money;
}

int Loan::getId()
{
    return id;
}