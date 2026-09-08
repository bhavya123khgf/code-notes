// wap to add two complex no's using operator overloading
#include <iostream>
using namespace std;

class Complex
{ 
    int r,i;
    public:
    void getdata()
    {
        cout<<"enter value of real part and imaginary part of complex no"<<endl;
        cin>>r>>i;
    }
    void display()
    {
        cout<<r<<" + "<<i<<"i"<<endl;
    }
    Complex operator + (Complex bb)
    {
        Complex cc;
        cc.r=r+bb.r;
        cc.i=i+bb.i;
        return cc;
    }
};
int main()
{
    Complex aa;
    aa.getdata();
    Complex bb;
    bb.getdata();
    Complex cc;
    cc=aa+bb;
    cc.display();
    return 0;
}