#include "Account.h"
#include "Client.h"

int Account::count = 0;
double Account::defaultInterestRate = 0.01;

Account::Account(int n, Client* o) : number(n), balance(0), interestRate(defaultInterestRate), owner(o), partner(nullptr) { count++; }
Account::Account(int n, Client* o, double ir) : number(n), balance(0), interestRate(ir), owner(o), partner(nullptr) { count++; }
Account::Account(int n, Client* o, Client* p) : number(n), balance(0), interestRate(defaultInterestRate), owner(o), partner(p) { count++; }
Account::Account(int n, Client* o, Client* p, double ir) : number(n), balance(0), interestRate(ir), owner(o), partner(p) { count++; }

int Account::GetNumber() { return number; }
double Account::GetBalance() { return balance; }
double Account::GetInterestRate() { return interestRate; }
Client* Account::GetOwner() { return owner; }
Client* Account::GetPartner() { return partner; }
bool Account::CanWithdraw(double a) { return a <= balance; }
void Account::Deposit(double a) { balance += a; }
bool Account::Withdraw(double a) { if (CanWithdraw(a)) { balance -= a; return true; } return false; }
void Account::AddInterest() { balance += balance * interestRate; }
void Account::SetInterest(double ir) { interestRate = ir; }

int Account::GetCount() { return count; }
double Account::GetDefaultInterestRate() { return defaultInterestRate; }
void Account::SetDefaultInterestRate(double ir) { defaultInterestRate = ir; }