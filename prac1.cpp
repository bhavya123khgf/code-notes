#include <iostream>
#include <cstring>
using namespace std;

class Smartdevice
{
    int deviceid;
    char* firmwarevirsion;
    double powerconsumption;
    public:
    static int count;

    Smartdevice(int did, char* firm, double power)
    {
        deviceid = did;
        firmwarevirsion = new char[strlen(firm)+1];
        strcpy(firmwarevirsion, firm);
        powerconsumption = power;
        count++;
    }
    Smartdevice(Smartdevice& aa)
    {
        deviceid=aa.deviceid;
        powerconsumption=aa.powerconsumption;
        firmwarevirsion=new char[strlen(aa.firmwarevirsion)+1];
        strcpy(firmwarevirsion, aa.firmwarevirsion);
        count++;
    }
    ~Smartdevice()
    {
        delete[]firmwarevirsion;
    }
    void updateFirmware(char* newVersion)
    {
        delete[]firmwarevirsion;
        firmwarevirsion = new char[strlen(newVersion) + 1];
        strcpy(firmwarevirsion,newVersion);
    }
};
void displaycount()
{
    cout<<"count = "<<Smartdevice::count<<endl;
}
int Smartdevice::count=0;
int main()
{
    Smartdevice Device1(123,"snapdragon8",6000);
    Smartdevice Device2(Device1);
    Device2.updateFirmware("snapdragon 8 elite");
    displaycount();
}