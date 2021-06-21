#include<iostream>
using namespace std;

int partition(int* arr, int start, int end)
{
    int pivot = arr[start];
    int pivotIndex = start;
    while(true)
    {
        if(pivot>=arr[start])
            start+=1;
        else if(pivot<arr[end])
            end-=1;
        else if(start<end)
        {
            arr[start]^=arr[end];
            arr[end]^=arr[start];
            arr[start]^=arr[end];
            start+=1;
            end-=1;
        }
        else
            break;
    }
    arr[pivotIndex] = arr[end];
    arr[end] = pivot;
    return end;
}

void quickSort(int* arr, int low, int high)
{
    if(low<high)
    {
        int mid = partition(arr, low, high);
        quickSort(arr, 0, mid-1);
        quickSort(arr, mid+1, high);
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

    quickSort(arr, 0, size-1);

    cout<<"Sorted output : ";
    for(int i=0; i<size; i++)
        cout<<arr[i]<<" ";

    return 0;
}