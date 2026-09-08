#include <iostream>
#include <iomanip>
using namespace std;

// Abstract Base Class
class BankAccount 
{
protected:
double balance;
public:
BankAccount(double bal) : balance(bal) {}
virtual double calculateInterest() = 0; // Pure virtual
double getBalance() const { return balance; }
// Overload + operator to add balances
double operator+(const BankAccount& other) {
double cc;
cc=balance+other.balance;
return cc;
}
virtual ~BankAccount() {}
};
// Derived class: Savings Account
class SavingsAccount : public BankAccount {
public:
SavingsAccount(double bal) : BankAccount(bal) {}
double calculateInterest() override {
double interest = balance * 0.04;
if (balance > 10000)
interest += balance * 0.01; // 1% bonus
return interest;
}
};
// Derived class: Checking Account
class CheckingAccount : public BankAccount {
public:
CheckingAccount(double bal) : BankAccount(bal) {}
double calculateInterest() override {
double interest = balance * 0.02;
return interest - 5; // Rs. 5 fee
}
};
// Derived class: Business Account
class BusinessAccount : public BankAccount {
public:
BusinessAccount(double bal) : BankAccount(bal) {}
double calculateInterest() override {
double interest = balance * 0.05;
if (balance > 50000)
interest += balance * 0.02; // 2% extra
return interest;
}
};
// Main function
int main() {
// Upcasting: base class pointers to derived objects
BankAccount* acc1 = new SavingsAccount(15000);
BankAccount* acc2 = new CheckingAccount(8000);
BankAccount* acc3 = new BusinessAccount(60000);
cout << "Savings Account Interest: Rs. " << acc1->calculateInterest() << endl;
cout << "Checking Account Interest: Rs. " << acc2->calculateInterest() << endl;
cout << "Business Account Interest: Rs. " << acc3->calculateInterest() << endl;
// Operator overloading demo
double totalBalance = *acc1 + *acc3;
cout << "Combined Balance of Savings and Business Account: Rs. " << totalBalance <<endl;
// Clean up
delete acc1;
delete acc2;
delete acc3;
return 0;
}