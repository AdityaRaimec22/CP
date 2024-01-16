#include<bits/stdc++.h>
using namespace std;

int getKthLargest(vector<int> &arr, int k)
{
    priority_queue<int, vector<int>, greater<int> > pq;

    int n = arr.size();
    for(int i = 0; i < n; i++)
    {
        int sum = 0;
        for(int j = 0; j < k; j++)
        {
            sum += arr[j];
            if(pq.size() < k)
            {
                pq.push(sum);
            }
            else
            {
                if(pq.top() < sum)
                {
                    pq.pop();
                    pq.push(sum);
                }
            }
        }
    }
    return pq.top();
}

int main(){


    return 0;
}