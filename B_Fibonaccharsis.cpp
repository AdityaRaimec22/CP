#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define f(i, j, n) for (ll i = j; i < n; i++)
#define fo(i, j) for (auto i : j)
#define vec vector<ll>

ll fibbo(ll n)
{
    if (n < 0)
    {
        return -1;
    }
    vec dp(n + 1);
    dp[0] = 0;
    dp[1] = 1;

    f(i, 2, n + 1)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    return dp[n];
}

void solve1()
{

    ll n, k;
    cin >> n >> k;

    ll a, b;
    if (n % 2 == 0)
    {
        a = b = n / 2;
    }
    else
    {
        a = n / 2;
        b = n / 2 + 1;
    }

    if (a == 0 && b == 0)
    {
        cout << 0 << endl;
        return;
    }

    ll count = 0;
    while (b <= 2 * a)
    {

        if (a < fibbo(k - 3))
        {
            cout << count << endl;
            return;
        }

        if (b - a >= fibbo(k - 4))
            count++;
        b++;
        a--;
    }

    cout << count << endl;
}

void solve()
{
    ll n, k, ans = 0;
    cin >> n >> k;
    if (k >= 29)
    {
        cout << 0;
        return;
    }
    vector<ll> fibonacci(29, 1);
    for (int i = 2; i <= 28; i++)
        fibonacci[i] = fibonacci[i - 1] + fibonacci[i - 2];
    ll x = fibonacci[k - 3], y = fibonacci[k - 2]; // x=1 , y=2
    for (int i = 0; i <= n; i++)
    {
        ll temp = n - y * i;
        if (temp >= 0 and temp % x == 0)
        {
            if (i >= temp / x)
                ans++;
        }
    }
    cout << ans;
}

int main()
{
    ll t;
    cin >> t;

    while (t--)
    {
        solve();
        cout << endl;
    }

    return 0;
}