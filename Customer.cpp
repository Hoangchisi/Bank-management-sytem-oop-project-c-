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
    int pos;
    pos = findAccount(accountId,creditAccountList);

    if(pos != -1) 
    {
        creditAccountList[pos].depositMoney(nMoney);
        std::cout<<"Successfully deposited "<<nMoney<<"!"<<'\n';
        return;
    }

    pos = findAccount(accountId,debitAccountList);

    if(pos != -1)
    {
        debitAccountList[pos].depositMoney(nMoney);
        std::cout<<"Successfully deposited "<<nMoney<<"!"<<'\n';
        return;
    }
    std::cout<<"Account was not found!!!"<<'\n';
    
}

void Customer::createAccount(int nMoney, std::string type)
{

    if(nMoney < 10000)
    {
        std::cout<<"You must have at least 10000 to create an account!"<<'\n';
        return;
    }

    if(type == "c")
    {
        creditAccountList.push_back(CreditAccount(id,nMoney));
   
        std::cout<<"Successfully created credit account with id: ";
        std::cout<<creditAccountList[creditAccountList.size()-1].getId()<<'\n';
    }
    
    else
    {
        debitAccountList.push_back(DebitAccount(id,nMoney));
   
        std::cout<<"Successfully created debit account with id: ";
        std::cout<<debitAccountList[debitAccountList.size()-1].getId()<<'\n';
    }
}

void Customer::deleteAccount(int accountId)
{
    int pos = findAccount(accountId, creditAccountList);

    if(pos != -1) 
    {
        // return money to customer
        std::cout<<"Give you back "<<creditAccountList[pos].getMoney()<<'\n'; 
        creditAccountList.erase(creditAccountList.begin() + pos);
        std::cout<<"Successfully deleted account!"<<'\n';
        return;
    }
    
    pos = findAccount(accountId, debitAccountList);

    if(pos != -1) 
    {
        // return money to customer
        std::cout<<"Give you back "<<debitAccountList[pos].getMoney()<<'\n'; 
        debitAccountList.erase(debitAccountList.begin() + pos);
        std::cout<<"Successfully deleted account!"<<'\n';
        return;
    }

    std::cout<<"Account was not found!!!"<<'\n';
}


void Customer::generalInquiry()
{
    std::cout<<"Customer's information:"<<'\n';
    std::cout<<"Name: "<<name<<'\n';
    std::cout<<"Address: "<<address<<'\n';
    std::cout<<"Phone number: "<<phoneNo<<'\n';

    std::cout<<"-------------------------\n";
    std::cout<<"Credit accounts: "<<'\n';
    for(int i = 0; i < creditAccountList.size(); i++)
    {
        std::cout<<"ID: "<<creditAccountList[i].getId()<<' ';
        std::cout<<"| money: "<<creditAccountList[i].getMoney()<<'\n';
    }

    std::cout<<"-------------------------\n";
    std::cout<<"Debit accounts: "<<'\n';
    for(int i = 0; i < debitAccountList.size(); i++)
    {
        std::cout<<"ID: "<<debitAccountList[i].getId()<<' ';
        std::cout<<"| money: "<<debitAccountList[i].getMoney()<<'\n';
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
    int pos = findAccount(accountId,creditAccountList);

    if(pos != -1)
    {
        creditAccountList[pos].withdrawMoney(nMoney);
        return;
    }

    pos = findAccount(accountId, debitAccountList);

    if(pos != -1)
    {
        debitAccountList[pos].withdrawMoney(nMoney);
        return;
    }

    std::cout<<"Account was not found!!!"<<'\n';
}

int Customer::findAccount(int accountId, std::vector<CreditAccount> accountList)
{
    for (int i = 0; i < accountList.size(); i++)
        if(accountList[i].getId() == accountId)
            return i;
    return -1;
}

int Customer::findAccount(int accountId, std::vector<DebitAccount> accountList)
{
    for (int i = 0; i < accountList.size(); i++)
        if(accountList[i].getId() == accountId)
            return i;
    return -1;
}

void Customer::applyForLoan(std::string type, int accountId, int loanMoney)
{

    int pos = findAccount(accountId,creditAccountList);

    if(pos != -1)
    {
        // if type is 'mortgage'
        if(type == "mortgage")
        {
            std::cout<<"Successfully loan "<<loanMoney<<"!"<<'\n';
            // successfully lending money
            creditAccountList[pos].depositMoney(loanMoney);
            // add loan to loan list
            loanList.push_back(Loan(type,accountId,id,loanMoney));
        }

        // if type is 'trust'
        if(type == "trust")
        {
            // can only loan the amount of money that is not exceeding 2 times of the amount of money in account
            if(loanMoney > 2*creditAccountList[pos].getMoney())
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

        return;
    }

    pos = findAccount(accountId,debitAccountList);

    if(pos != -1)
    {
        std::cout<<"Successfully loan "<<loanMoney<<"!"<<'\n';
        loanList.push_back(Loan(type,accountId,id,loanMoney));
        return;
    }

    std::cout<<"Account was not found!!!"<<'\n';

}