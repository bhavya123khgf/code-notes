#include <iostream>
using namespace std;

template<typename T>
class Pair
{
T first,second;
public:
Pair(T a, T b): first(a), second(b){}
void getsum()
{
    cout<<first+second<<endl;
}
};
int main()
{
    Pair<int> aa(20,10);
    aa.getsum();
    Pair<double> bb(11.1,22.2);
    bb.getsum();
    return 0;
}
