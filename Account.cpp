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
// -------------------------------------------
// Credit account

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

//--------------------------------------------
//Debit account
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