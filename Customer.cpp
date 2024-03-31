#include "Customer.h"
#include <iostream>
#include <vector>
int Customer::countId = 0;
Customer::Customer()
{
    id = countId++;
    name = "noName";
    address = "undefined";
    phoneNo = 0;
}

Customer::Customer(std::string newName, std::string newAddress, int newPhoneNo)
{
    id = countId++;
    name = newName;
    address = newAddress;
    phoneNo = newPhoneNo;
}

int Customer::getId()
{
    return id;
}

void Customer::depositMoney(int nMoney, int accountId)
{
    /// add money 
    int pos = findAccount(accountId);

    if(pos == -1) 
    {
        std::cout<<"Account was not found!!!"<<'\n';
        return;
    }

    accountList[pos].depositMoney(nMoney);
    std::cout<<"Deposited successfully!"<<'\n';
}

void Customer::createAccount(int nMoney)
{
    if(nMoney < 10000)
    {
        std::cout<<"You must have at least 10000 to create an account!"<<'\n';
        return;
    }
    accountList.push_back(Account(id,nMoney));
   
    std::cout<<"Successfully created account with id: ";
    std::cout<<accountList[accountList.size()-1].getId()<<'\n';
}

void Customer::deleteAccount(int accountId)
{
    int pos = findAccount(accountId);

    if(pos == -1) 
    {
        std::cout<<"Account was not found!!!"<<'\n';
        return;
    }
    // return money to customer
    std::cout<<"Give you back "<<accountList[pos].getMoney()<<'\n'; 
    accountList.erase(accountList.begin() + pos);
    std::cout<<"Successfully deleted account!"<<'\n';
}


void Customer::generalInquiry()
{
    std::cout<<"Customer's information:"<<'\n';
    std::cout<<"Name: "<<name<<'\n';
    std::cout<<"Address: "<<address<<'\n';
    std::cout<<"Phone number: "<<phoneNo<<'\n';

    std::cout<<"-------------------------\n";
    std::cout<<"Accounts: "<<'\n';
    for(int i = 0; i < accountList.size(); i++)
    {
        std::cout<<"ID: "<<accountList[i].getId()<<' ';
        std::cout<<"| money: "<<accountList[i].getMoney()<<'\n';
    }
    std::cout<<"-------------------------\n";
    std::cout<<"Loans: "<<'\n';
    for(int i = 0; i < loanList.size(); i++)
    {
        std::cout<<"ID: "<<loanList[i].getId()<<' ';
        std::cout<<"| money: "<<loanList[i].getMoney()<<'\n';
    }
    std::cout<<"-------------------------\n";
}

void Customer::withdrawMoney(int nMoney, int accountId)
{
    int pos = findAccount(accountId);

    if(pos == -1) 
    {
        std::cout<<"Account was not found!!!"<<'\n';
        return;
    }
    if(accountList[pos].getMoney() < nMoney)
    {
        std::cout<<"The amount exceeding your balance!!!"<<'\n';
        return;
    }
    std::cout<<"Successfully withdrew "<<nMoney<<"!"<<'\n';
    accountList[pos].withdrawMoney(nMoney);
}

int Customer::findAccount(int accountId)
{
    for (int i = 0; i < accountList.size(); i++)
        if(accountList[i].getId() == accountId)
            return i;
    return -1;
}

void Customer::applyForLoan(std::string type, int accountId, int loanMoney)
{

    int pos = findAccount(accountId);

    // find if the account is found or not
    if(pos == -1)
    {
        std::cout<<"Account was not found!!!"<<'\n';
        return;
    }
    // if type is 'mortgage'
    if(type == "mortgage")
    {
        std::cout<<"Successfully loan "<<loanMoney<<"!"<<'\n';
        // successfully lending money
        accountList[pos].depositMoney(loanMoney);
        // add loan to loan list
        loanList.push_back(Loan(type,accountId,id,loanMoney));
    }

    // if type is 'trust'
    if(type == "trust")
    {
        // can only loan the amount of money that is not exceeding 2 times of the amount of money in account
        if(loanMoney > 2*accountList[pos].getMoney())
        {
            std::cout<<"Unsuccessfully loan "<<loanMoney<<"!!!\n";
            std::cout<<"The amount can't exceed 2 times of amount of money in the account!"<<'\n';
        }

        // successfully loan 
        else
        {
            std::cout<<"Successfully loan "<<loanMoney<<"!"<<'\n';
            loanList.push_back(Loan(type,accountId,id,loanMoney));
        }
    }
}