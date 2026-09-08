#include <iostream>
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
    }
    Buffer(const Buffer& aa)
    {
        size=aa.size;
        data=new char[size+1];
        strcpy(data,aa.data);
        count++;
    }   
    ~Buffer()
    {
        delete[]data;
    }
    friend Buffer operator+(const Buffer&b1,const Buffer&b2);
};
int Buffer::count=0;
Buffer operator+(const Buffer&b1,const Buffer&b2)
{
    int newsize=b1.size+b2.size;
    char* tempstr=new char[newsize+1];
    strcpy(tempstr,b1.data);
    strcat(tempstr,b2.data);
    Buffer tempobj(tempstr);
    delete[]tempstr;
    return tempobj;
}
int main()
{
    Buffer b1("bhavya");
    Buffer b2=b1;
    b2.reverse();
    Buffer b3=b1+b2;
    cout << "b1: "<<b1.data<< endl;
    cout << "b2: "<<b2.data<< endl;
    cout << "b3: "<<b3.data<<endl;
    cout << "Active Buffers: " << Buffer::count<< endl;
}
