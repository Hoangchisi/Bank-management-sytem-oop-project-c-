#include <string>
#ifndef LOAN_H
#define LOAN_H

class Loan
{
private:
    static int countId;
    int id;
    int accountId;
    int customerId;
    int money;
public:
    std::string type;
    

    Loan();
    
    Loan(std::string newType, int newAccountId,int newCustomerId,int nMoney);

    void changeMoney(int nMoney);

    int getMoney();

    int getId();

};
#endif