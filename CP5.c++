#include<bits/stdc++.h>
#define ll long long int
using namespace std;

ll cmp(pair<ll, ll> a, pair<ll, ll> b)
{
    if(a.second == b.second)
    {
        return a.first > b.first;
    }
    return a.second < b.second;
}

ll minCost(vector<pair<ll, ll> > v, ll n, ll k)
{
    ll count = 0;
    ll sc = 0;
    ll cost = 0;
    ll temp = 0;

    for(auto i: v)
    {
        if(i.second < k && sc < n && count < n)
        {
            count++;
            sc += 1 + i.first;
        }
        else
        {
            break;
        }
    }

    cost = count*k;

    if(count == n)
    {
        return cost;
    }

    temp = n - count;

    for(auto i: v)
    {
        if(temp >= i.first)
        {
            cost += i.first*i.second;
            temp = temp - i.first;
        }
        else
        {
            cost += temp*i.second;
            break;
        }
    }
    return cost;
}

int main() {

    ll t;
    cin >> t;
    while(t--)
    {
        ll n, k;
        cin >> n >> k;
        ll a[n], b[n];
        for(ll i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for(ll i = 0; i < n; i++)
        {
            cin >> b[i];
        }

        vector<pair<ll, ll>> v;

        for(ll i = 0; i < n; i++)
        {
            pair<ll, ll> p = make_pair(a[i], b[i]);
            v.push_back(p);
        }

        sort(v.begin(), v.end(), cmp);

        cout << minCost(v, n, k) << endl;
    }
    return 0;
}
