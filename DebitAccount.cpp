#include "DebitAccount.h"
#include <iostream>

DebitAccount::DebitAccount(int newCustomerId, int newMoney)
{
    id = countId++;
    customerId = newCustomerId;
    money = newMoney;
}

void DebitAccount::withdrawMoney(int nMoney)
{
    money -= nMoney;
    std::cout<<"Successfully withdrew "<<nMoney<<"!"<<'\n';
}