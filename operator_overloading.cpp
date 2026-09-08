#include <iostream>
using namespace std;

class A
{
    int x,y;
    public:
    void getdata()
    {
        cout<<"enter two no's"<<endl;
        cin>>x>>y;
    }
    void display()
    {
        cout<<"value of x and y is "<<x<<","<<y<<endl;
    }
    A operator +(A &bb)
    {
        A cc;
        cc.x=x+bb.x;
        cc.y=y+bb.y;
        return cc;
    }

};
int main()
{
    A aa;
    aa.getdata();
    A bb;
    bb.getdata();
    A cc;
    cc=aa+bb;
    aa.display();
    bb.display();
    cc.display();
    return 0;
}