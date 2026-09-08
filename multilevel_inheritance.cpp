#include <iostream>
using namespace std;

class Person
{
    protected:
    string name;
    public:
    Person(string s):name(s){}
};
class Student:public Person
{
    protected:
    int rollno;
    public:
    Student(string s,int r):Person(s),rollno(r){}
};
class Enggstudent:public Student
{
    private:
    string branch;
    public:
    Enggstudent(string s,int r,string b):Student(s,r),branch(b){}
    void display()
    {
        cout<<"name of student: "<<name<<endl;
        cout<<"roll no of student: "<<rollno<<endl;
        cout<<"branch of student: "<<branch<<endl;
    }
};
int main()
{
    Enggstudent aa("Bhavya Bhatia",472,"CSE");
    aa.display();
}