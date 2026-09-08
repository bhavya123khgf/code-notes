#include <iostream>
using namespace std;

class Employee
{
    protected:
    double salary;
    public:
    void setdata(double sal){salary=sal;}

};
class Developer:public Employee
{
    private:
    double bonus;
    public:
    void setbonus(double b){bonus=b;}
    void displaysal()
    {
        cout<<"salary of the employee is: "<<salary+bonus<<endl;
    }
};
int main()
{
    Developer aa;
    aa.setdata(15000);
    aa.setbonus(1000);
    aa.displaysal();
}