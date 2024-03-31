#include "Teller.h"
#include "Customer.h"
#include <string>
int Teller::countId = 0;
Teller::Teller()
{
    id = countId++;
    name = "Layla";

}

Teller::Teller(std::string newName)
{
    id = countId++;
    name = newName;
}

void Teller::addCustomer(Customer customer)
{
    customerList.push_back(customer);
}

void Teller::openAccount(int customerId, int nMoney)
{
    customerList[customerId].createAccount(nMoney);
}

void Teller::closeAccount(int customerId, int accountId)
{
    customerList[customerId].deleteAccount(accountId);
}

void Teller::provideInfo(int customerId)
{
    customerList[customerId].generalInquiry();
}

void Teller::collectMoney(int customerId, int accountId ,int nMoney)
{
    customerList[customerId].depositMoney(nMoney,accountId);
}

void Teller::loanRequest(int customerId, int accountId, int loanMoney, std::string type)
{
    customerList[customerId].applyForLoan(type,accountId,loanMoney);
}
void Teller::withdrawRequest(int customerId, int accountId,int nMoney)
{
    customerList[customerId].withdrawMoney(nMoney,accountId);
}