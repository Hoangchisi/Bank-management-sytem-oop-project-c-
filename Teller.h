#include <string>
#include <vector>
#include "Customer.h"
#ifndef TELLER_H
#define TELLER_H

class Teller
{
private:
    static int countId;
    int id;
public:
    std::string name;
    std::vector<Customer> customerList;

    //default constructor
    Teller();

    Teller(std::string newName);

    void addCustomer(Customer customer);

    void collectMoney(int customerId,int accountId ,int nMoney);

    void openAccount(int customerId, int nMoney);

    void closeAccount(int customerId, int accountId);

    void loanRequest(int customerId, int accountId, int loanMoney, std::string type);

    void withdrawRequest(int customerId, int accountId,int nMoney);

    void provideInfo(int customerId);
};

#endif