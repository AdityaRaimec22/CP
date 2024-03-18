#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll nC3(ll& n)
{
    if(n < 3)
    {
        return 0;
    }

    return n*(n-1)*(n-2)/6;
}

ll nC2(ll &n)
{
    if(n == 0)
    {
        return 0;
    }

    return n*(n-1)/2;
}

ll nC1(ll &n)
{
    if(n == 0)
    {
        return 0;
    }

    return n;
}

ll countTriangle(ll& n, map<ll, ll> &mp)
{
    if(n < 3)
    {
        return 0;
    }
    
    ll triangleSum = 0;
    ll beforeTriangleSum = 0;

    for(auto i: mp)
    {
        ll x = 0;
        ll y = 0;
        for(auto j: mp)
        {
            if(j.first == i.first && j.second >= 2)
            {
                y = nC2(j.second);
                beforeTriangleSum += x*y;
                break;
            }
            else if(j.first < i.first)
            {
                x += nC1(j.second);
            }
            else
            {
                break;
            }
        }

        triangleSum += nC3(i.second) + beforeTriangleSum;
        beforeTriangleSum = 0;
    }

    return triangleSum;
}

int main() {

    ll t;
    cin >> t;

    while (t--)
    {
        ll n;
        cin >> n;
        map<ll, ll> mp;

        for(ll i = 0; i < n; i++)
        {
            ll a;
            cin >> a;
            mp[a]++;
        }
        cout << countTriangle(n, mp) << endl;
    }

    return 0;
}