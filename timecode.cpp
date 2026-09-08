#include <iostream>
using namespace std;

class Time
{
    int h,m;
public:
    void input()
    {
        cout<<"enter hours and minutes"<<endl;
        cin>>h>>m;
    } 
    void display()
    {
        cout<<"hours ="<< h <<" and minutes ="<< m <<endl;
    }
    void sum(Time aa,Time bb)
    {
        h=(aa.m+bb.m)/60;
        h=h+aa.h+bb.h;
        m=(aa.m+bb.m)%60;
    }
};
int main()
{
    Time t1,t2,t3;
    t1.input();
    t2.input();
    t3.sum(t1,t2);
    t1.display();
    t2.display();
    t3.display();
    return 0;
}