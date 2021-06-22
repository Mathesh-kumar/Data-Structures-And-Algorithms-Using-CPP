#include<iostream>
using namespace std;

void merge(int* arr, int low, int mid, int high)
{
    int size1 = (mid-low)+1, size2 = high-mid;
    int arr1[size1], arr2[size2];

    int k=0;
    for(int i=low; i<=mid; i++)
        arr1[k++] = arr[i];
    
    k=0;
    for(int i=mid+1; i<=high; i++)
        arr2[k++] = arr[i];

    int i=0, j=0;
    while(true)
    {
        while(arr1[i]<=arr2[j] && i<size1)
            arr[low++] = arr1[i++];
        
        if(i==size1)
        {
            while(j<size2)
                arr[low++] = arr2[j++];
            break;
        }

        while(arr2[j]<arr1[i] && j<size2) 
            arr[low++] = arr2[j++];
        
        if(j==size2)
        {
            while(i<size1)
                arr[low++] = arr1[i++];
            break;
        }
    }
}

void mergeSort(int* arr, int low, int high)
{
    if(low<high)
    {
        int mid = (low+high)/2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid+1, high);
        merge(arr, low, mid, high);
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

    mergeSort(arr, 0, size-1);

    cout<<"Sorted output : ";
    for(int i=0; i<size; i++)
        cout<<arr[i]<<" ";

    return 0;
}