#include <iostream>
using namespace std;

class Account
{
    double balance;
    static const int maxlimit = 5000;
    static double totalmoneywithdrawn;
    public:
    Account(double b) : balance(b){}
    void withdraw(double w)
    {
        if(w + totalmoneywithdrawn > maxlimit) cout<<"transaction failed"<<endl;
        else if(w>balance) cout<<"transaction failed due to insufficiant funds"<<endl;
        else
        {
            totalmoneywithdrawn+=w;
            balance -=w;
            cout<<"transaction successful"<<endl;
            cout<<"remaining balance"<<balance<<endl;
        }
    }
    void print()
    {
        cout<<"remaining money you can withdraw "<<totalmoneywithdrawn<<endl;
        cout<<"max limit"<<endl;
    }
};

double Account::totalmoneywithdrawn=0;
int main()
{
    Account aa(25000);
    aa.withdraw(30000);
    aa.withdraw(4000);
    aa.withdraw(1000);
    aa.withdraw(2000);
}