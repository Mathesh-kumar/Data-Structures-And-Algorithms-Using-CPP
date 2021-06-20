#include<iostream>
using namespace std;

void bubbleSort(int* arr, int n)
{
    for(int i=0; i<n; i++)
    {
        bool swap = false;
        for(int j=0; j<n-1; j++)
        {
            if(arr[j]>arr[j+1])
            {
                arr[j]^=arr[j+1];
                arr[j+1]^=arr[j];
                arr[j]^=arr[j+1];
                swap = true;
            }
        }
        if(swap)
            continue;
    }
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