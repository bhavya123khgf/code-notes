#include<iostream>
using namespace std;

class bank
{
    public:
    virtual double calculateInterest() = 0; // Pure virtual
    virtual ~bank() {}
};
//examples of how to override in a derived class    
class account:public bank
{
    double calculateInterest() override {
    /*double interest = balance * 0.04;*/}
};
class check : public bank
{
    double calculateInterest() override {
    /*double interest = balance * 0.02;
    return interest - 5; // Rs. 5 fee*/
    }
};