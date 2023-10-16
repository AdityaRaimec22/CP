#include <stdio.h>
#include <stdlib.h>

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

int binarySearch(int arr[], int size, int num)
{
    int s, mid, l;
    s = 0;
    l = size - 1;
    mid = (s+l)/2;

    while (s <= l)  
    {
        if(num < mid) {
            l = mid -1;
        }

        else if (num > mid)
        {
            s = mid + 1;
        }
        else if (num == mid)
        {
            return mid;
        }   
    }
    return -1;
    
}

void BubbleSort(int a[], int n)
{
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < n - i -1; j++)
    //     {
    //         if (a[j] > a[j+1])
    //         {
    //             int temp = a[j + 1];
    //             a[j + 1] = a[j];
    //             a[j] = temp;
    //         }
    //     }
    // }

    int counter = 1;
    while (counter < n)
    {
        for (int i = 0; i < n - counter; i++)
        {
            if(a[i]>a[i+1]){
                int temp = a[i];
                a[i] = a[i+1];
                a[i+1] = temp;
            }
        }
        counter++;
    }
    
}

void insertionSort(int arr[], int size)
{
    for (int i = 1; i < size; i++)
    {
        int current = arr[i];
        int j = i - 1;
        while (arr[j] > current && j>=0)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j+1] = current;
    }
}

int main()
{

    int arr[] = {1, 2, 3, 4, 5, 56, 6, 7, 8};

    int size = sizeof(arr) / sizeof(int);

    // linearSearch(arr,56);
    int num = 56;

    BubbleSort(arr,size);
    // insertionSort(arr,8);
    int i = binarySearch(arr, size, 56);

    for (int i = 0; i < size; i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");

    printf("the element %d was found at %dth position\n", num, i);

    return 0;
}