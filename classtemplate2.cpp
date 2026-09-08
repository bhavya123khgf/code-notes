#include <iostream>
using namespace std;

template <class T1,class T2>
class Entry
{
    T1 key;
    T2 value;
    public:
    Entry(T1 a,T2 b): key(a), value(b){}
    void printdata()
    {
        cout<<"key: "<<key<<" value: "<<value<<endl;
    }
};
int main(){
    Entry<int,string> aa(32,"ronaldo");
    aa.printdata();
    return 0;
}