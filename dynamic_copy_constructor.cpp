#include <iostream>
using namespace std;

class Student
{
    string name;
    int* cgpa;
public:
    Student(string s, int cg)
    {
        name=s;
        cgpa = new int;
        *cgpa = cg;
    }
    Student(Student& s1)
    {
        name=s1.name;
        cgpa=new int;
        *cgpa = *(s1.cgpa);
    }
    ~Student()
    {
        delete cgpa;
        cout<<"deconstructor have been called for"<<name<<endl;
    }
    void display()
    {
        cout<<name << " | CGPA: " << *cgpa << " | Address: " << cgpa << endl;
    }

};
int main()
{
    Student s1("Bhavya Bhatia",9);
    Student s2(s1);
    s1.display();
    s2.display();
}