#include<iostream>
using namespace std;

void selectionSort(int* arr, int n)
{
    for(int i=0; i<n; i++)
    {
        int minIndex = i;
        for(int j=i; j<n; j++)
            if(arr[minIndex] > arr[j])
                minIndex = j;
        if(minIndex != i)
        {
            arr[i]^=arr[minIndex];
            arr[minIndex]^=arr[i];
            arr[i]^=arr[minIndex];
        }
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

    selectionSort(arr, size);

    cout<<"Sorted output : ";
    for(int i=0; i<size; i++)
        cout<<arr[i]<<" ";

    return 0;
}