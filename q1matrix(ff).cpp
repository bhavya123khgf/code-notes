#include <iostream>
using namespace std;

// Global constants for matrix limits
const int MAX_ROWS = 3;
const int MAX_COLS = 3;

class Matrix {
private:
    int mat[MAX_ROWS][MAX_COLS];
    int rows, cols;
    
    // Static member to keep track of how many Matrix objects exist
    static int count;

public:
    // 1. Default Constructor
    // Initializes a 3x3 matrix filled with zeros
    Matrix() {
        rows = MAX_ROWS;
        cols = MAX_COLS;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                mat[i][j] = 0;
            }
        }
        count++; // Increment object counter
    }

    // 2. Parameterized Constructor
    // Initializes matrix with values from a provided 2D array
    Matrix(int arr[MAX_ROWS][MAX_COLS], int r, int c) {
        rows = r;
        cols = c;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                mat[i][j] = arr[i][j];
            }
        }
        count++; // Increment object counter
    }

    // 3. Method Overloading: Add another Matrix
    // Adds two Matrix objects together and returns a new Matrix
    Matrix add(const Matrix& m) {
        Matrix result; // Creates a temporary object to hold the sum
        result.rows = rows;
        result.cols = cols;

        // Check if dimensions are compatible for addition
        if (rows != m.rows || cols != m.cols) {
            cout << "Matrix dimensions mismatch!" << endl;
            return result;
        }

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                result.mat[i][j] = mat[i][j] + m.mat[i][j];
            }
        }
        return result;
    }

    // 4. Method Overloading: Add a scalar
    // Adds a single integer to every element in the matrix
    Matrix add(int scalar) {
        Matrix result;
        result.rows = rows;
        result.cols = cols;

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                result.mat[i][j] = mat[i][j] + scalar;
            }
        }
        return result;
    }

    // Friend function declaration: Allows an external function to access private 'mat'
    friend void display(const Matrix& m);

    // Constant member function: Displays dimensions
    void getSize() const {
        cout << "Matrix size: " << rows << " x " << cols << endl;
    }

    // Static member function: Can be called without an object instance
    static int getCount() {
        return count;
    }
};

// Initialize the static member (required outside the class)
int Matrix::count = 0;

// Definition of the friend function 'display'
void display(const Matrix& m) {
    for (int i = 0; i < m.rows; ++i) {
        for (int j = 0; j < m.cols; ++j) {
            cout << m.mat[i][j] << "\t"; // Using tab for better alignment
        }
        cout << endl;
    }
    cout << endl;
}

int main() {
    // Data for initialization
    int arr1[MAX_ROWS][MAX_COLS] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int arr2[MAX_ROWS][MAX_COLS] = {{9, 8, 7}, {6, 5, 4}, {3, 2, 1}};

    // Creating objects
    Matrix m1(arr1, 3, 3); // Calls Parameterized constructor
    Matrix m2(arr2, 3, 3); // Calls Parameterized constructor
    Matrix m3;             // Calls Default constructor

    cout << "--- Matrix 1 ---\n";
    display(m1);

    cout << "--- Matrix 2 ---\n";
    display(m2);

    // Matrix + Matrix addition
    Matrix m4 = m1.add(m2);
    cout << "--- Matrix 1 + Matrix 2 ---\n";
    display(m4);

    // Matrix + Scalar addition
    Matrix m5 = m1.add(10);
    cout << "--- Matrix 1 + Scalar 10 ---\n";
    display(m5);

    // Displaying metadata
    m1.getSize();
    
    // Accessing the static count via the class name
    cout << "Total Matrix objects created: " << Matrix::getCount() << endl;

    return 0;
}