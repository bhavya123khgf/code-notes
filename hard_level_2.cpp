#include <iostream>
using namespace std;

class Person
{
    string name;
    public:
    Person(string n):name(n){}
    void showperson()
    {
        cout<<"name of person is: "<<name<<endl;
    }
};
class Faculty:virtual public Person
{
    protected:
    int facultyid;
    public:
    Faculty(string n,int id):Person(n),facultyid(id){}
    void showfaculty()
    {
        cout<<"ID of faculty is: "<<facultyid<<endl;
    }
};
class Student:virtual public Person
{
    protected:
    int studentid;
    public:
    Student(string n,int id):Person(n),studentid(id){}
    void showstudent()
    {
        cout<<"ID of student is: "<<studentid<<endl;
    }
};
class Teachingassistant: public Student, public Faculty
{
    string courseassigned;
    public:
    Teachingassistant(string n,int fid,int sid,string course):Person(n),Faculty(n,fid),Student(n,sid),courseassigned(course){}
    void showTAdetails()
    {
        showperson();
        showfaculty();
        showstudent();
    }
};
int main()
{
    Teachingassistant aa("bhavya",472,274,"CSE");
    aa.showTAdetails();
    aa.showperson();

}