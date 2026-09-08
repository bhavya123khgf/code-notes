#include <iostream>
using namespace std;

class Vehicle
{
    protected:
    string brand;
    public:
    Vehicle(string b):brand(b){};
};
class Car:public Vehicle
{
    private:
    string model;
    public:
    Car(string b,string m):Vehicle(b),model(m){}
    void display()
    {
        cout<<"the car is: "<<brand<<" "<<model<<endl;
    }
};
int main()
{
    Car aa("Tata","Hexa");
    aa.display();

}