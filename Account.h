#ifndef ACCOUNT_H
#define ACCOUNT_H

class Account
{
protected:
    int money;
    static int countId;
    int id;
    int customerId;
public:
    // default constructor
    Account();

    Account(int customerId,int newMoney);

    int getId();

    int getMoney();

    void depositMoney(int nMoney);

};

#endif