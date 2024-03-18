#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define f(i, j, n) for (ll i = j; i < n; i++)
#define fo(i, j) for (auto i : j)
#define vec vector<ll>

long long power(ll base, ll exponent)
{
    if (exponent == 0)
        return 1;
    else if (exponent % 2 == 0)
    {
        long long half = power(base, exponent / 2);
        return half * half;
    }
    else
    {
        return base * power(base, exponent - 1);
    }
}

void solve()
{
    // cout << " hello" << endl;
    ll a, b, l;
    cin >> a >> b >> l;
    ll p=a,q=b;
    ll count = 0;
    ll pa = 1, pb =1; 
    while (a < l)
    {
        if (l % a == 0)
        {
            pa++;
        }
        else
        {
            break;
        }
        a = a * p;
    }

    while (b < l)
    {
        if (l % b == 0)
        {
            pb++;
        }
        else
        {
            break;
        }
        b = b * q;
    }
    

    // ll pa = power(l, 1.0 / a);
    // ll pb = power(l, 1.0 / b);

    // cout << pa << " " << pb << endl;

    set<ll> s;

    for (ll i = 0; i < pa + 1; i++)
    {
        for (ll j = 0; j < pb + 1; j++)
        {
            ll vala = power(p, i);
            ll valb = power(q, j);

            ll f = vala*valb;

            if(f <= l && l%f == 0) {
                s.insert(l / (f));
            }
        }
    }

    cout << s.size() << endl;
}

int main()
{

    ll t;
    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}
