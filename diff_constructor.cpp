#include <iostream>
using namespace std;

class A
{
    int x;
    public:
    void getdata()
    {
        cout<<"enter a number"<<endl;
        cin>>x;
    }
    void display()
    {
        cout<<x<<endl;
    }
    A()
    {
        x=10;
    }
    A(A &a)
    {
        x=a.x;
    }
};
int main()
{
    A p;
    p.getdata();
    A q;
    A r(p);
    A s(q);
    p.display();
    q.display();
    r.display();
    s.display();
    return 0;
}