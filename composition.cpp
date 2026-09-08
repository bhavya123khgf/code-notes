#include <iostream>
using namespace std;

// 1. Inheritance Base
class Person {
public:
    Person() { cout << "[Inherit] Person arrives." << endl; }
    virtual ~Person() { cout << "[Inherit] Person leaves." << endl; }
};

// 2. The Part for Composition
class Rifle {
public:
    Rifle() { cout << "  [Comp] Rifle issued." << endl; }
    ~Rifle() { cout << "  [Comp] Rifle returned." << endl; }
};

// 3. Derived Class with Composition
class Soldier : public Person {
private:
    Rifle myRifle; // COMPOSITION: Rifle is part of Soldier
public:
    Soldier() { cout << " [Soldier] Soldier ready." << endl; }
    ~Soldier() { cout << " [Soldier] Soldier dismissed." << endl; }
};

// 4. Another Derived Class
class Medic : public Person {
public:
    Medic() { cout << " [Medic] Medic ready." << endl; }
    ~Medic() { cout << " [Medic] Medic dismissed." << endl; }
};

// 5. Aggregation: Squad HAS-A Medic (Independent)
class Squad {
private:
    Medic* squadMedic; // AGGREGATION: Pointer to an external object
public:
    Squad(Medic* m) : squadMedic(m) { 
        cout << "[Squad] Squad formed with a Medic." << endl; 
    }
    ~Squad() { cout << "[Squad] Squad disbanded." << endl; }
};

int main() {
    cout << "--- MISSION START ---" << endl;
    
    // Create the Medic on the Heap (Independent of the Squad)
    Medic* globalMedic = new Medic();
    
    cout << "\n--- ENTERING LOCAL BLOCK ---" << endl;
    {
        Soldier s;       // Local Soldier (and their Rifle)
        Squad alpha(globalMedic); // Squad borrows the Medic
    } 
    // At this '}', Soldier 's' and Squad 'alpha' are destroyed.
    
    cout << "\n--- LOCAL BLOCK ENDED ---" << endl;
    cout << "Is the Medic still alive?" << endl;
    
    delete globalMedic; // We must delete the Medic manually
    
    cout << "--- MISSION END ---" << endl;
    return 0;
}