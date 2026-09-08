#include <iostream>
using namespace std;

class Shape
{
    public:
    string color;
    Shape(string c):color(c){}
};
class Rectangle : public Shape
{
    public:
    int width;
    int length;
   
    Rectangle(string c,int l,int w):Shape(c),length(l),width(w){}
    void display()
    {
        cout<<"Length of rectangle:"<<length<<endl;
        cout<<"width of rectangle:"<<width<<endl;
        cout<<"color of rectangle:"<<color<<endl;
    }
};
int main()
{
    
    Rectangle aa("Red",10,20);
    aa.display();
}