#include <iostream>
using namespace std;

template <class T>
T getmax(T a,T b)
{
    if (a > b)
        return a;
    else
        return b;
}
int main()
{
    int i=5,j=10;
    float x=5.5,y=1.1;
    cout<<"maxcount= "<<getmax(i,j)<<endl;
    cout<<"maxcount= "<<getmax(x,y)<<endl;
    return 0;
}