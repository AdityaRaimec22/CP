#include <iostream>
using namespace std;

void BubbleSort(int *arr, int size)
{
    if(size == 0 || size == 1)
        return;

    for(int i = 0; i < size-1; i++)
    {
        if(arr[i] > arr[i+1])
            swap(arr[i],arr[i+1]);
    }

    BubbleSort(arr, size-1);
}

int main()
{
    int arr[] = {5,2,7,4,2,6,9,5};
    int size = sizeof(arr)/sizeof(int);
    BubbleSort(arr, size);
    for(int i = 0; i < size; i++)
    {
        cout << arr[i] <<" ";
    }cout<<endl;
    return 0;
}