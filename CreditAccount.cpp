#include "CreditAccount.h"
#include <iostream>
CreditAccount::CreditAccount(int newCustomerId, int newMoney)
{
    id = countId++;
    customerId = newCustomerId;
    money = newMoney;
}

void CreditAccount::withdrawMoney(int nMoney)
{
    if(money < nMoney)
    {
        std::cout<<"Unsuccessfully withdrew money!!! Please check your balance!"<<'\n';
        return;
    }
    money -= nMoney;
    std::cout<<"Successfully withdrew "<<nMoney<<"!"<<'\n';
}