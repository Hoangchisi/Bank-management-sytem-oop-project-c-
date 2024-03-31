#include<string>
#include "Teller.h"
#ifndef BANK_H
#define BANK_H

class Bank
{
private:
    int bankId;
    static int countId;
public:
    
    std::string name,location;
    Teller teller;

    /// default constructor 
    Bank();

    Bank(std::string newName, std::string newLocation);

    void getMenu();

    void printHello();
    
    void haveNewCustomer();

    void addCustomer();
};
#endif