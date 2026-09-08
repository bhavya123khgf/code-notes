#include <iostream>
#include <string>
using namespace std;
class InternationalShip {
protected:
    string name;
    int fuelCapacity;
    double valuation;
    string owningCompany;
    double insurancePremium;
public:
    void setBaseDetails(string n, int fc, double v, string oc) {
        name = n;
        fuelCapacity = fc;
        valuation = v;
        owningCompany = oc;
    }
    virtual void computeInsurance() = 0; 
    virtual ~InternationalShip(){}
};
class CruiseShip : public InternationalShip {
    int noOfPassengers;
    int noOfPools;
    double foodStorage;
public:
    void setCruiseDetails(int p, int pools, double fs) {
        noOfPassengers = p;
        noOfPools = pools;
        foodStorage = fs;
    }
    void computeInsurance() override {
        insurancePremium = (valuation + fuelCapacity + foodStorage) / (noOfPassengers * noOfPools);
        cout << "Cruise Ship [" << name << "] Insurance Premium: $" << insurancePremium << endl;
    }
};
class CargoCarrier : public InternationalShip {
    int noOfCrews;
    int noOfRiskyZones;
    double inflammableMaterialsQuantity;
public:
    void setCargoDetails(int c, int rz, double imq) {
        noOfCrews = c;
        noOfRiskyZones = rz;
        inflammableMaterialsQuantity = imq;
    }
    void computeInsurance() override {
        insurancePremium = ((valuation + fuelCapacity) * noOfRiskyZones + inflammableMaterialsQuantity) / (noOfCrews * 1000);
        cout << "Cargo Carrier [" << name << "] Insurance Premium: $" << insurancePremium << endl;
    }
};
int main() {
    CruiseShip myCruise;
    myCruise.setBaseDetails("Ocean Dream", 50000, 2000000.0, "Royal Sea");
    myCruise.setCruiseDetails(2000, 5, 5000.0);
    myCruise.computeInsurance();
    CargoCarrier myCargo;
    myCargo.setBaseDetails("Heavy Hauler", 80000, 1500000.0, "Global Logix");
    myCargo.setCargoDetails(50, 3, 2000.0);
    myCargo.computeInsurance();
    return 0;
}