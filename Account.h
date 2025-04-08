#pragma once
class Client;

class Account {
private:
    int number;
    double balance;
    double interestRate;
    Client* owner;
    Client* partner;
    static int count;
    static double defaultInterestRate;
public:
    Account(int n, Client* o);
    Account(int n, Client* o, double ir);
    Account(int n, Client* o, Client* p);
    Account(int n, Client* o, Client* p, double ir);

    int GetNumber();
    double GetBalance();
    double GetInterestRate();
    Client* GetOwner();
    Client* GetPartner();

    bool CanWithdraw(double a);
    void Deposit(double a);
    bool Withdraw(double a);
    void AddInterest();
    void SetInterest(double ir);

    static int GetCount();
    static double GetDefaultInterestRate();
    static void SetDefaultInterestRate(double ir);
};