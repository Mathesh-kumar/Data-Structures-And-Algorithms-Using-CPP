#include<iostream>
using namespace std;

void bubbleSort(int* arr, int n)
{
    bool swap = false;
    for(int i=0; i<n-1; i++)
    {
        if(arr[i]>arr[i+1])
        {
            arr[i]^=arr[i+1];
            arr[i+1]^=arr[i];
            arr[i]^=arr[i+1];
            swap = true;
        }
    }
    if(swap)
        bubbleSort(arr, n);
}

int main()
{
    int size;
    cout<<"Enter size of array : ";
    cin>>size;

    int *arr = new int(size);
    cout<<"Enter elements of array : ";
    for(int i=0; i<size; i++)
        cin>>arr[i];

    bubbleSort(arr, size);

    cout<<"Sorted output : ";
    for(int i=0; i<size; i++)
        cout<<arr[i]<<" ";

    return 0;
}