#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
#define ll long long
#define f(i, j, n) for (ll i = j; i < n; i++)
#define fo(i, j) for (auto i : j)
#define vec vector<ll>

ll gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

void solve()
{
    ll n, x, y;
    cin >> n >> x >> y;

    ll divXY = 0;

    ll lcm = (x * y) / gcd(x, y);     // Calculate the least common multiple (LCM) of x and y
    ll minMultiple = (n / lcm) * lcm; // Find the largest multiple of lcm <= n

    divXY = minMultiple / lcm;

    for (ll i = minMultiple + lcm; i <= n; i += lcm)
    {
        divXY++;
    }

    ll rightSum = 0;
    ll leftSum = 0;

    ll divX = n / x - divXY;
    ll divY = n / y - divXY;

    rightSum = (divX*(2*n+1-divX))/2;

    leftSum = (divY*(divY+1))/2;

    cout << rightSum - leftSum << endl;
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