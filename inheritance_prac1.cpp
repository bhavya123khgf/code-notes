#include <iostream>
using namespace std;

class Employee
{
    protected:
    int employeeid;
    string name;
    void getbasicinfo()
    {
        cout<<"enter employee id: "<<endl;
        cin>>employeeid;
        cout<<"enter employee name: "<<endl;
        cin>>name;
    }
};
class Fulltimeemployee:public Employee
{
    float monthlysalary;
    float bonus;
    public:
    void getdata()
    {
        Employee::getbasicinfo();
        cout<<"enter monthly salary: "<<endl;
         cin>>monthlysalary;
        cout<<"enter bonus: "<<endl;
         cin>>bonus;
    }
    void calculatepay()
    {
        cout<<"calculated pay: "<<monthlysalary+bonus<<endl;
    }
};
class Partimeemployee:public Employee
{
    int hoursworked;
    float hourlyrate;
    public:
    void getdata()
    {
        Employee::getbasicinfo();
        cout<<"enter hours worked: "<<endl;
        cin>>hoursworked;
        cout<<"enter hourlyrate: "<<endl;
        cin>>hourlyrate;
    }
    void calculatepay()
    {
        cout<<"calculated pay: "<<hourlyrate*hoursworked<<endl;
    }
};
int main()
{
    Fulltimeemployee aa;
    aa.getdata();
    aa.calculatepay();
    Partimeemployee bb;
    bb.getdata();
    bb.calculatepay();
}