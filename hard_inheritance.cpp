#include <iostream>
using namespace std;

class Publication
{
    protected:
    string title;
    float price;
    public:
    void putdata()
    {
        cout<<"title of the book is: "<<title<<endl;
        cout<<"price of the book is: "<<price<<endl;
    }
    void getdata()
    {
        cout<<"enter title of the book: "<<endl;
        cin>>title;
        cout<<"enter price of the book: "<<endl;
        cin>>price;
    }
    
};
class Book:public Publication
{
    protected:
    int pagecount;
    public:
    void putdata()
    {
        Publication :: putdata();
        cout<<"pagecount of the book is: "<<pagecount<<endl;
    }
    void getdata()
    {
        Publication::getdata();
        cout<<"enter pagecount of the book: "<<endl;
        cin>>pagecount;
    }
};
class Ebook:public Book
{
    float downloadsize;
    public:
    void putdata()
    {
        Book::putdata();
        cout<<"download size of the book is: "<<downloadsize<<endl;
    }
    void getdata()
    {
        Book::getdata();
        cout<<"enter download size of the book: "<<endl;
        cin>>downloadsize;
    }
};
int main()
{
    Ebook aa[3];
    for(int i=0;i<3;i++)
    {
        cout<<"entering details of ebook "<<i+1<<endl;
        aa[i].getdata();
    }
    for(int i=0;i<3;i++)
    {
        cout<<"displaying details of ebook "<<i+1<<endl;
        aa[i].putdata();
    }
}