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

class CreditAccount:public Account
{
public:
    void withdrawMoney(int nMoney);
    CreditAccount(int newCustomerId, int newMoney);
};

class DebitAccount:public Account
{
public:
    void withdrawMoney(int nMoney);
    DebitAccount(int newCustomerId, int newMoney);
};

#endif