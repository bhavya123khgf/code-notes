#include <iostream>
using namespace std;

void printdata(int x)
{
    cout<<"value of x in normal function is: "<<x <<endl;
}
template <typename t>
void printdata(t x){
    cout<<"value of x in template is: "<<x<<endl;
}
int main()
{
    printdata(10);
    printdata(10.5);
    printdata("ID");
//force template for int value:
    printdata<int>(10);
}