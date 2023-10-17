#include <stdio.h>

int linearSearch(int arr[], int size, int num)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == num)
        {
            return i;
        }
    }
        return -1;
}

int BinarySearch(int arr[], int size, int element)
{
    int low, mid, high;
    low = 0;
    high = size - 1;
    
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (arr[mid] == element)
        {
            return mid;
        }
        
        else if (element > arr[mid])
        {
            low = mid + 1;
        }
        else if (element < arr[mid])
        {
            high = mid - 1;
        }
        // return mid;
    }
    return -1;
}

void bubbleSort(int a[], int n)
{
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < n - i ; j++)
        {
            if (a[j] > a[j+1])
            {
                int temp = a[j + 1];
                a[j + 1] = a[j];
                a[j] = temp;
            }
        }
    }
}

void insertionSort(int a[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int current = a[i];
        int j = i - 1;
        while (a[j] > current && j >= 0)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = current;
    }
}

int main()
{
    int arr[] = {10, 14, 32, 35, 53, 20000000, 67, 12, 89, 1, 5, 7};
    int size = sizeof(arr)/sizeof(int);
    int element = linearSearch(arr, size, 32);
    bubbleSort(arr, size);
    int element2 = BinarySearch(arr, size, 32);
    printf("the element 32 is found at %dth position\n",element);
    printf("the element 32 is found at %dth position\n",element2);
    return 0;
}