#include <iostream>
using namespace std;
// MAX-HEAPIFy
void maxHeapify(int A[], int i, int n)
{
    int left = 2 * i;
    int right = 2 * i + 1;
    int largest;
    // Check left child
    if (left <= n && A[left] > A[i])
        largest = left;
    else
        largest = i;
    // Check right child
    if (right <= n && A[right] > A[largest])
        largest = right;

    // If largest is not the current node
    if (largest != i)
    {
        // Exchange
        int temp = A[i];
        A[i] = A[largest];
        A[largest] = temp;

        // Move down the tree
        maxHeapify(A, largest, n);
    }
}
// BUILD-MAX-HEAP
void buildMaxHeap(int A[], int n)
{
    for (int i = n / 2; i >= 1; i--)
    {
        maxHeapify(A, i, n);
    }
}
// Display heap
void display(int A[], int n)
{
    for (int i = 1; i <= n; i++)
    {
        cout << A[i] << " ";
    }
    cout << endl;
}
int main()
{
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    int A[100];
    cout << "Enter elements: ";
    for (int i = 1; i <= n; i++)
    {
        cin >> A[i];
    }
    cout << "\nOriginal array: ";
    display(A, n);
    // Convert array into Max Heap
    buildMaxHeap(A, n);
    cout << "Max Heap: ";
    display(A, n);
    return 0;
}