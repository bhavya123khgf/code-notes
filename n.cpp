#include <iostream>
#include <string>
#include <exception>

using namespace std;
class Exception
{
    
    public:string message;
    Exception(string msg):message(msg){}
};

// The Railway System Class
class RailwaySystem {
private:
    int totalSeats;

public:
    RailwaySystem(int seats) : totalSeats(seats) {}

    void bookTicket(string name, int age, int requestedSeats) {
        // Case 1: Invalid Input (Negative numbers)
        if (age < 0 || requestedSeats <= 0) {
            throw Exception("Invalid Input: Age or ticket count cannot be negative/zero.");
        }

        // Case 2: Age below 5
        if (age < 5) {
            throw Exception("Booking Denied: Children under 5 are not allowed to travel alone.");
        }

        // Case 3: Exceeding available seats
        if (requestedSeats > totalSeats) {
            throw Exception("Availability Error: Not enough seats available.");
        }

        // If no exceptions were thrown, complete the booking
        totalSeats -= requestedSeats;
        cout << "\n--- Booking Successful! ---" << endl;
        cout << "Passenger: " << name << endl;
        cout << "Tickets Booked: " << requestedSeats << endl;
        cout << "Remaining Seats: " << totalSeats << endl;
    }
};

int main() {
    RailwaySystem irctc(50); // Initialize with 50 available seats
    string name;
    int age, count;

    cout << "--- Railway Ticket Booking System ---" << endl;
    cout << "Enter Name: ";
    getline(cin, name);
    cout << "Enter Age: ";
    cin >> age;
    cout << "Number of Tickets: ";
    cin >> count;

    try {
        irctc.bookTicket(name, age, count);
    } 
    catch (Exception& e) {
        // This catches the 'runtime_error' thrown above
        cout << "\n[EXCEPTION CAUGHT]: " << e.message << endl;
    }

    cout << "\nProgram continues running... Have a nice day!" << endl;

    return 0;
}