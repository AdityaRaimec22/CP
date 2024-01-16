#include <iostream>
using namespace std;

void Heapify(int arr[], int n, int i)
{
    int largest = i;
    int left = 2*i;
    int right = 2*i + 1;

    if(left <= n && arr[left] > arr[largest])
    {
        largest = left;
    }
    if(right <= n && arr[right] > arr[largest])
    {
        largest = right;
    }

    if(largest != i)
    {
        swap(arr[largest], arr[i]);
        Heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n)
{
    int size = n;

    while (size > 1)
    {
        swap(arr[size], arr[1]);
        size--;

        Heapify(arr, size, 1);
    }
}

int main()
{

    return 0;
}