#include "Bank.h"
#include <iostream>

using namespace std;

int main()
{
    Bank bankList[] = {Bank("SEA", "Viet Nam")};

    bankList[0].haveNewCustomer();

    return 0;
}
