#include <iostream>
using namespace std;

template<typename T1>
class Analyzer
{
    public:
    Analyzer(T1 var)
    {cout<<var<<"is not a character"<<endl;}
};
template<>
class Analyzer<char>
{
    public:
    Analyzer(char var)
    {
        if(var>='As'&&var<='Z')
        {cout<<var<<" is an uppercase"<<endl;}
        else
        {cout<<var<<" is not an uppercase"<<endl;}
    }
};
int main()
{
    Analyzer<int> a(5);
    Analyzer<char> b('G');
    return 0;
}