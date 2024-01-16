#include <iostream>
#include <vector>
using namespace std;

void Heapify(vector<int> arr, int n, int i)
{
    int largest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if(left < n && arr[left] > arr[largest])
    {
        largest = left;
    }
    if(right < n && arr[right] > arr[largest])
    {
        largest = right;
    }

    if(largest != i)
    {
        swap(arr[largest], arr[i]);
        Heapify(arr, n, largest);
    }
}

vector<int> mergeHeaps(vector<int> v1, vector<int> v2, int n, int m)
{
    vector<int> ans;

    for(auto i: v1)
        ans.push_back(i);
    for(auto i:v2)
        ans.push_back(i);

    for(int i = n/2-1; i >= 0; i--)
    {
        Heapify(ans, n, i);
    }
}

int main()
{

    return 0;
}