#include <iostream>
using namespace std;
class Student
{
    string name;
    int rollno;
    public:
    Student(string s,int r):name(s) , rollno(r){cout<<"constructor was called for "<<name<<endl;}
    ~Student(){cout<<"deconstructor was called for "<<name<<endl;}
    void printdata()
    {
        cout<<"Name of student: "<<name<<endl;
        cout<<"Roll no of student: "<<rollno<<endl;
    }
};
int main(){
    Student* s1=new Student("Bhavya Bhatia",472);
    s1->printdata();
    delete s1;
}