#include<iostream>
using namespace std;

void insertionSort(int* arr, int n)
{
    for(int i=1; i<n; i++)
    {
        if(arr[i-1] > arr[i])
        {
            int key = arr[i], j=i-1;
            while(j >= 0 && arr[j] > key)
                arr[j+1] = arr[j--];
            arr[j+1] = key;
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

    insertionSort(arr, size);

    cout<<"Sorted output : ";
    for(int i=0; i<size; i++)
        cout<<arr[i]<<" ";

    return 0;
}