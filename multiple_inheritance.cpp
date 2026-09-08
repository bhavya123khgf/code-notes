#include <iostream>
using namespace std;

class Student
{
    protected:
    int studentid;
    double cgpa;
    public:
    Student(int s,double c):studentid(s),cgpa(c){}
};
class Salary
{
    protected:
    int sal;
    public:
    Salary(int sa):sal(sa){}
};
class Teachingassistant:public Student,public Salary
{
    string subject;
    public:
    Teachingassistant(int s,double c,int sa,string sub):Student(s,c),Salary(sa),subject(sub){}
    void display()
    {
        cout<<"student roll no: "<<studentid<<endl;
        cout<<"student cgpa: "<<cgpa<<endl;
        cout<<"salary of teacher: "<<sal<<endl;
        cout<<"subject of teacher: "<<subject<<endl;
    }
};
int main()
{
    Teachingassistant aa(472,8.18,25000,"Edd");
    aa.display();
}