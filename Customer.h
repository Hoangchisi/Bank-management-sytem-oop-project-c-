#include <string>
#include <vector>
#include "Loan.h"
#include "Account.h"
#ifndef CUSTOMER_H
#define CUSTOMER_H

class Customer
{
private:
    static int countId;
    int id;
    std::string address;
    int phoneNo;
    std::vector<CreditAccount> creditAccountList;
    std::vector<DebitAccount> debitAccountList;
    std::vector<Loan> loanList;

public:
    
    std::string name;

    Customer();

    Customer(std::string newName, std::string newAddress, int newPhoneNo);

    int getId();
    
    void generalInquiry();

    void depositMoney(int nMoney, int accountId);

    void withdrawMoney(int nMoney, int accountId);

    void createAccount(int nMoney, std::string type);

    void deleteAccount(int accountId);
    
    void applyForLoan(std::string type, int accountId, int loanMoney);

    int findAccount(int accountId, std::vector<CreditAccount>);

    int findAccount(int accountId, std::vector<DebitAccount>);
};
#endif