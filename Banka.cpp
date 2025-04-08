#include "Bank.h"
#include <iostream>
using namespace std;

Bank::~Bank() {
    for (auto c : clients) delete c;
    for (auto a : accounts) delete a;
}

Client* Bank::CreateClient(int code, string name) {
    Client* c = new Client(code, name);
    clients.push_back(c);
    return c;
}

Account* Bank::CreateAccount(int n, Client* o) {
    Account* a = new Account(n, o);
    accounts.push_back(a);
    return a;
}

Account* Bank::CreateAccount(int n, Client* o, double ir) {
    Account* a = new Account(n, o, ir);
    accounts.push_back(a);
    return a;
}

Account* Bank::CreateAccount(int n, Client* o, Client* p) {
    Account* a = new Account(n, o, p);
    accounts.push_back(a);
    return a;
}

Account* Bank::CreateAccount(int n, Client* o, Client* p, double ir) {
    Account* a = new Account(n, o, p, ir);
    accounts.push_back(a);
    return a;
}

void Bank::AddInterest() {
    for (auto acc : accounts) {
        acc->AddInterest();
    }
}

void Bank::ChangeDefaultInterestRate(double newRate) {
    double oldRate = Account::GetDefaultInterestRate();
    for (auto acc : accounts) {
        if (acc->GetInterestRate() == oldRate) {
            acc->SetInterest(newRate);
        }
    }
    Account::SetDefaultInterestRate(newRate);
}

void Bank::PrintAccounts() {
    for (auto acc : accounts) {
        cout << "Účet #" << acc->GetNumber()
             << ", stav: " << acc->GetBalance()
             << ", úrok: " << acc->GetInterestRate() << endl;
    }
}
