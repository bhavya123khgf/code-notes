#include <iostream>
#include <stdexcept>

using namespace std;

const int MAX_SIZE = 100;
class Exception{
public:
string message;
Exception(string msg): message(msg){}
};

template <typename T>
class GenericContainer {
private:    
    T data[MAX_SIZE]; // Static array
    int size;

public:
    GenericContainer() {
        size = 0;
    }

    void addElement(T element) {
        if (size >= MAX_SIZE)
            throw Exception("Container is full. Cannot add more elements.");
        data[size++] = element;
    }

    void removeElement(int index) {
        if (size == 0)
            throw Exception("Cannot remove from an empty container.");
        if (index < 0 || index >= size)
            throw Exception("Invalid index for removal.");

        for (int i = index; i < size - 1; ++i) {
            data[i] = data[i + 1];
        }
        --size;
    }

    T getElement(int index) {
        if (index < 0 || index >= size)
            throw Exception("Index out of bounds.");
        return data[index];
    }

    int getSize() {
        return size;
    }

    void display() {
        cout << "Container elements: ";
        for (int i = 0; i < size; ++i) {
            cout << data[i] << " ";
        }
        cout << endl;
    }
};

// Main function to demonstrate
int main() {
    try {
        GenericContainer<int> container;
        container.addElement(10);
        container.addElement(20);
        container.addElement(30);
        container.display();

        cout << "Element at index 1: " << container.getElement(1) << endl;

        container.removeElement(1);
        container.display();

        // Trigger underflow exception
        container.removeElement(0);
        container.removeElement(0);
        container.removeElement(0); // This will throw the exception
        
    } catch ( Exception& e) {
        cout << "Error: " << e.message << endl;
    }

    return 0;
}