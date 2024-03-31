#ifndef ACCOUNT_H
#define ACCOUNT_H

class Account
{
private:
    int money;
    static int countId;
    int id;
    int customerId;
public:
    // default constructor
    Account();

    Account(int newCustomerId, int newMoney);

    void depositMoney(int nMoney);

    void withdrawMoney(int nMoney);

    int getId();

    int getMoney();

};


#endif