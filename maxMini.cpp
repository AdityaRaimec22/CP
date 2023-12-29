#include <iostream>
#include <deque>
using namespace std;

int maxMini(int arr[], int n, int k)
{
    deque <int> maxi;
    deque <int> mini;

    for (int i = 0; i < k; i++)
    {
        while (!maxi.empty() && arr[maxi.back()] <= arr[i])
        {
            maxi.pop_back();
        }
        
        while (!mini.empty() && arr[mini.back()] >= arr[i])
        {
            mini.pop_back();
        }

        maxi.push_back(i);
        mini.push_back(i);
        
    }
    int ans = 0;
    ans += arr[maxi.front()] + arr[mini.front()];

    for (int i = k; i < n; i++)
    {
        //removal
        
    }
    
    
    
    
}

int main()
{
    
    return 0;
}