#include <iostream>
using namespace std;

template <typename t1,typename t2>
void display(t1 a,t2 b)
{
    cout<<"first "<<a<<" second "<<b<<endl;
}
int main()
{
    display(11,12.5);
    display("ID",12);
    return 0;
}