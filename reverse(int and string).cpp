#include <iostream>
#include <cstring>

using namespace std;
class Reverse
{
    int x;
    public:
    void getdata()
    {
        cout<<"enter a number"<<endl;
        cin>>x;
    }
    
    void reverse()
    {
        int rev=0;
        while(x>0)
        {
        rev=(rev*10)+x%10;
        x=x/10;
        }
        cout<<"reverse of the no is"<<rev<<endl;

    }
};
int main()
{
    Reverse r1;
    r1.getdata();
    r1.reverse();
    return 0;
}
/*#include <iostream>
#include <cstring>
using namespace std;
class Buffer
{
     public:
    char *data;
    int size;
    static int count;
    public:
    Buffer(const char* input)
    {
        size=strlen(input);
        data = new char[size+1];
        strcpy(data,input);
        count++;
    }
    void reverse()
    {
        if (size<=1) return;
        else{
            char*start=data;
            char*end=data+size-1;
            while(start<end)
            {
                char temp= *start;
                *start=*end;
                *end= temp;
                start++;end--;
            }
        }
    }*/