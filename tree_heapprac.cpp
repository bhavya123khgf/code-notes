#include <iostream>
using namespace std;

void MaxHeapify(int a[],int i,int n)
{
    int left = 2*i;
    int right = 2*i+1;
    int largest;
    //check left
    if(left<=n && a[left]>a[i])largest = left;
    else largest=i;
    //check right
    if(right<=n && a[right]>a[largest])largest=right;

    if(largest!=i)
    {
        swap(a[i],a[largest]);
        MaxHeapify(a,largest,n);
    }
}
void buildheap(int a[],int n)
{
    for(int i=n/2;i>=1;i--)
    {
        MaxHeapify(a,i,n);
    }
}
void display(int a[],int n)
{
    for(int i=1;i<=n;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
}
int main()
{
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    int A[n];
    cout << "Enter elements: ";
    for (int i = 1; i <= n; i++)
    {
        cin >> A[i];
    }
    cout << "\nOriginal array: ";
    display(A, n);
    // Convert array into Max Heap
    buildheap(A, n);
    cout << "Max Heap: ";
    display(A, n);
    return 0;
}