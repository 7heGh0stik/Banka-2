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

// --- main.cpp ---
#include "Bank.h"
#include <iostream>
using namespace std;

int main() {
    Bank banka;

    Client* c1 = banka.CreateClient(1, "Novák");
    Client* c2 = banka.CreateClient(2, "Svoboda");

    Account* a1 = banka.CreateAccount(100, c1);
    Account* a2 = banka.CreateAccount(101, c2, 0.03);

    a1->Deposit(1000);
    a2->Deposit(2000);

    cout << "Před úrokem:\n";
    banka.PrintAccounts();

    banka.AddInterest();

    cout << "\nPo připsání úroku:\n";
    banka.PrintAccounts();

    banka.ChangeDefaultInterestRate(0.05);

    cout << "\nPo změně výchozího úroku a aktualizaci účtů:\n";
    banka.PrintAccounts();

    cout << "ENTER to exit...";
    cin.get();
    return 0;
}
