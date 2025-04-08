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
