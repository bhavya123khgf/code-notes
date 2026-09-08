#include <iostream>
using namespace std;

class PoweredDevice {
public:
    int wattage;
    PoweredDevice(int w) : wattage(w) {
        cout << "[1] PoweredDevice built with " << wattage << "W" << endl;
    }
};

class Scanner : virtual public PoweredDevice {
public:
    // Scanner thinks it's setting wattage to 10
    Scanner() : PoweredDevice(10) { 
        cout << "[2] Scanner part built" << endl; 
    }
};

class Printer : virtual public PoweredDevice {
public:
    // Printer thinks it's setting wattage to 20
    Printer() : PoweredDevice(20) { 
        cout << "[3] Printer part built" << endl; 
    }
};

class AllInOneMachine : public Scanner, public Printer {
public:
    // THE BOSS: AllInOneMachine sets the REAL wattage to 50
    AllInOneMachine() : PoweredDevice(50), Scanner(), Printer() {
        cout << "[4] All-In-One Machine ready!" << endl;
    }
};

int main() {
    cout << "--- Starting Build ---" << endl;
    AllInOneMachine myMachine;
    cout << "--- Build Finished ---" << endl;
    
    cout << "Final Wattage: " << myMachine.wattage << "W" << endl;
    return 0;
}