#include<iostream>
using namespace std;

void selectionSort(int* arr, int n)
{
    for(int i=0; i<n; i++)
    {
        int min = arr[i], minIndex = i;
        for(int j=i; j<n; j++)
        {
            if(min > arr[j])
            {
                min = arr[j];
                minIndex = j;
            }
        }
        arr[minIndex] = arr[i];
        arr[i] = min;
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