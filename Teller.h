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
    std::vector<Customer> customerList;
public:
    std::string name;
    

    //default constructor
    Teller();

    Teller(std::string newName);

    //add a new customer
    void addCustomer(Customer customer);

    //collect money from customer and add money to account
    void collectMoney(int customerId,int accountId ,int nMoney);

    //open an account with the amount of money
    void openAccount(int customerId, int nMoney, std::string type);

    //close/delete an account and give return money
    void closeAccount(int customerId, int accountId);

    //apply loan request from customer
    void loanRequest(int customerId, int accountId, int loanMoney, std::string type);

    //apply withdraw request from customer
    void withdrawRequest(int customerId, int accountId,int nMoney);

    //inform the customer's information
    void provideInfo(int customerId);

    //check if the customer ID was invalid
    bool checkCustomerId(int customerId);
};

#endif