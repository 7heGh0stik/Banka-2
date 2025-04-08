#pragma once
#include "Account.h"
#include "Client.h"
#include <vector>

class Bank {
private:
    vector<Client*> clients;
    vector<Account*> accounts;
public:
    ~Bank();

    Client* CreateClient(int code, string name);
    Account* CreateAccount(int number, Client* owner);
    Account* CreateAccount(int number, Client* owner, double ir);
    Account* CreateAccount(int number, Client* owner, Client* partner);
    Account* CreateAccount(int number, Client* owner, Client* partner, double ir);

    void AddInterest();
    void ChangeDefaultInterestRate(double newRate);

    void PrintAccounts();
};