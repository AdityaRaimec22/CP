#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll minCost(ll arr[], ll n)
{
    priority_queue<ll, vector<ll>, greater<ll> > pq;
    for (int i = 0; i < n; i++)
    {
        pq.push(arr[i]);
    }
    int cost = 0;
    while (pq.size() > 1)
    {
        int a = pq.top();
        pq.pop();
        int b = pq.top();
        pq.pop();

        int sum = a+b;
        cost += sum;
        pq.push(sum);
    }

    return pq.top();
}

int main(){


    return 0;
}