#include "Bank.h"
#include<iostream>
#include <string>
using namespace std;

int Bank::countId = 0;
Bank::Bank()
{
    bankId = countId++;
    name = "noName";
    location = "noWhere";
}

Bank::Bank(std::string newName, std::string newLoaction)
{
    bankId = countId++;
    name = newName;
    location = newLoaction;
}

void Bank::getMenu()
{
    cout<<"------------------------"<<'\n';
    cout<<"What can i do for you?"<<'\n';
    cout << "1. General Inquiry \n";
    cout << "2. Deposit Money \n";
    cout << "3. Withdraw Money \n";
    cout << "4. Open Account \n";
    cout << "5. Close Account \n";
    cout << "6. Apply Loan For Account\n";
    cout << "0. Exit\n";
    cout<<"------------------------"<<'\n';

    cout<<"Please enter your option: ";
    int option, customerId, accountId,nMoney; 
    string type;
    cin>>option;

    switch (option)
    {
        case 0:
            cout<<"Thank you and see you!"<<'\n';
        break;
        case 1:

            cout<<"Please enter your customer ID: ";
            cin>>customerId;
            
            //invalid customer id
            if(customerId > teller.customerList.size())
            {
                cout<<"Invalid customer id!!!"<<'\n';
                getMenu();
                break;
            }

            system("cls");
            teller.provideInfo(customerId);
            getMenu();
        break;

        case 2:

            cout<<"Please enter the amount of money: ";
            cin>>nMoney;
            cout<<"Please enter your customer ID: ";
            cin>>customerId;

            if(customerId > teller.customerList.size())
            {
                cout<<"Invalid customer id!!!"<<'\n';
                getMenu();
                break;
            }

            cout<<"Please enter your account ID: ";
            cin>>accountId;

            system("cls");
            teller.collectMoney(customerId,accountId,nMoney);

            getMenu();
        break;

        case 3:

            cout<<"Please enter the amount of money: ";
            cin>>nMoney;
            cout<<"Please enter your customer ID: ";
            cin>>customerId;

            if(customerId > teller.customerList.size())
            {
                cout<<"Invalid customer id!!!"<<'\n';
                getMenu();
                break;
            }

            cout<<"Please enter your account ID: ";
            cin>>accountId;

            system("cls");
            teller.withdrawRequest(customerId,accountId,nMoney);

            getMenu();
        break;

        case 4:

            cout<<"Please enter the amount of money: ";
            cin>>nMoney;
            cout<<"Please enter your customer ID: ";
            cin>>customerId;
            
            if(customerId > teller.customerList.size())
            {
                cout<<"Invalid customer id!!!"<<'\n';
                getMenu();
                break;
            }

            system("cls");
            teller.openAccount(customerId,nMoney);

            getMenu();
        break;

        case 5:
            cout<<"Please enter your customer ID: ";
            cin>>customerId;

            if(customerId > teller.customerList.size())
            {
                cout<<"Invalid customer id!!!"<<'\n';
                getMenu();
                break;
            }

            cout<<"Please enter your account ID: ";
            cin>>accountId;

            system("cls");
            teller.closeAccount(customerId,accountId);

            getMenu();
        break;

        case 6:
        

            cout<<"Please enter the amount of money: ";
            cin>>nMoney;
            cout<<"Please enter your customer ID: ";
            cin>>customerId;

            if(customerId > teller.customerList.size())
            {
                cout<<"Invalid customer id!!!"<<'\n';
                getMenu();
                break;
            }

            cout<<"Please enter your account ID: ";
            cin>>accountId;
            cout<<"Please enter type of loan (trust/mortgage): ";
            getline(cin,type);
            getline(cin,type);

            system("cls");
            teller.loanRequest(customerId,accountId,nMoney,type);

            getMenu();
        break;

        default:
            system("cls");
            cout<<"Invalid option!!! Please select again!"<<'\n';
            getMenu();
        break;
    }
}

void Bank::printHello()
{
    cout<<"------------------------"<<'\n';
    cout<<"Welcome to "<< name << " bank!"<<'\n';
    cout<<"Have a good day!"<<'\n';
    cout<<"I am a teller. My name is "<<teller.name<<"."<<'\n';
    cout<<"------------------------"<<'\n';
}

void Bank::addCustomer()
{
    string name,address;
    int phoneNumber;

    cout<<"Please enter your name: ";
    getline(cin,name);
    cout<<"Please enter your address: ";
    getline(cin,address);
    cout<<"Please enter your phone number: ";
    cin>>phoneNumber;

    teller.customerList.push_back(Customer(name,address,phoneNumber));

    cout<<"Successfully registered! Your customer id is "<<teller.customerList.size() - 1<<'\n';
}

void Bank::haveNewCustomer()
{
    printHello();
    cout<<"Are you a new customer? (Yes: 1 | No: 0 | Exit: -1): ";
    int choice; string temp;
    cin>>choice; getline(cin,temp);

    switch (choice)
    {
        case 0:
            getMenu();   
            haveNewCustomer(); 
            break;
    
        case 1:
            addCustomer();
            getMenu();
            haveNewCustomer();
            break;

        case -1:
            cout<<"Thank you and see you!"<<'\n';
            break;
        default:
            cout<<"Invalid option!!! Please select again!"<<'\n';
            haveNewCustomer();
            break;
    }

}