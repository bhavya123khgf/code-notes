#include <iostream>
using namespace std;

class B;
class A
{
    int x;
    public:
    void getdata()
    {
        cout<<"enter a number x"<<endl;
        cin>>x;
    }
    friend void max(A,B);
};
class B
{
    int y;
    public:
    void get()
    {
        cout<<"enter a number y"<<endl;
        cin>>y;
    }
    friend void max(A,B);
};
void max(A a,B b)
{
    if(a.x>b.y)
    cout<<a.x<<" is greater than "<<b.y<<endl;
    else
    cout<<b.y<<" is greater than "<<a.x<<endl;
}
int main()
{
    A aa;
    B bb;
    aa.getdata();
    bb.get();
    max(aa,bb);
    return 0;
}