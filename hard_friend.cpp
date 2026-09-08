#include <iostream>
using namespace std;
class Bankaccount
{
int accoutno;
string accountholder;
double balance=0;
public:
Bankaccount(int no, string name,double bal) : accoutno(no), accountholder(name), balance(bal) {}
void printmasked()
{
    cout<<accountholder<<" "<<"accountno:**********"<<endl;
}
void deposit(double amount)
{
    balance += amount;
}
void withdraw(double amount)
{
    if(amount>0) balance -= amount;
}
void printbalance()
{
    cout<<balance<<endl;
}

friend void bankmanager(Bankaccount aa);
friend void incometaxdepartment(Bankaccount aa);
};

void bankmanager(Bankaccount aa)
{
cout<<"Manager access granted"<<endl;
cout<<"account holder name:"<<aa.accountholder<<endl;
cout<<"account no:"<<aa.accoutno<<endl;
cout<<"Balance:"<<aa.balance<<endl;
}
void incometaxdepartment(Bankaccount aa)
{
cout<<"ITD access granted"<<endl;
cout<<"account holder name for (ITD):"<<aa.accountholder<<endl;
cout<<"account no for (ITD):"<<aa.accoutno<<endl;
cout<<"Balance for (ITD):"<<aa.balance<<endl;
}
int main()
{
    Bankaccount aa(123456,"Bhavya Bhatia",25000);
    aa.printmasked();
    aa.deposit(15000);
    aa.printbalance();
    aa.withdraw(10000);
    aa.printbalance();
    bankmanager(aa);
    incometaxdepartment(aa);

}