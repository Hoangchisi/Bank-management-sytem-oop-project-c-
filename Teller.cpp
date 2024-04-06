#include "Teller.h"
#include "Customer.h"
#include <string>
#include<iostream>

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

bool Teller::checkCustomerId(int customerId)
{
    if(customerId >= customerList.size())
        return false;
    return true;
}

void Teller::addCustomer(Customer customer)
{
    customerList.push_back(customer);
    std::cout<<"Successfully registered! Your customer id is "<<customerList.size() - 1<<'\n';
}

void Teller::openAccount(int customerId, int nMoney, std::string type)
{
    if(!checkCustomerId(customerId))
    {
        std::cout<<"Invalid customer id!!!"<<'\n';
        return;
    }

    customerList[customerId].createAccount(nMoney,type);
}

void Teller::closeAccount(int customerId, int accountId)
{
    if(!checkCustomerId(customerId))
    {
        std::cout<<"Invalid customer id!!!"<<'\n';
        return;
    }
    customerList[customerId].deleteAccount(accountId);
}

void Teller::provideInfo(int customerId)
{
    if(!checkCustomerId(customerId))
    {
        std::cout<<"Invalid customer id!!!"<<'\n';
        return;
    }
    customerList[customerId].generalInquiry();
}

void Teller::collectMoney(int customerId, int accountId ,int nMoney)
{
    if(!checkCustomerId(customerId))
    {
        std::cout<<"Invalid customer id!!!"<<'\n';
        return;
    }
    customerList[customerId].depositMoney(nMoney,accountId);
}

void Teller::loanRequest(int customerId, int accountId, int loanMoney, std::string type)
{
    if(!checkCustomerId(customerId))
    {
        std::cout<<"Invalid customer id!!!"<<'\n';
        return;
    }
    customerList[customerId].applyForLoan(type,accountId,loanMoney);
}
void Teller::withdrawRequest(int customerId, int accountId,int nMoney)
{
    if(!checkCustomerId(customerId))
    {
        std::cout<<"Invalid customer id!!!"<<'\n';
        return;
    }
    customerList[customerId].withdrawMoney(nMoney,accountId);
}