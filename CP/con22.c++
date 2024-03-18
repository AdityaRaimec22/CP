#include <bits/stdc++.h>
#define forn(i, n, k) for (int i = k; i < n + k; i++)
#define all(v) v.begin(), v.end()
#define take(n) \
    ll n;       \
    cin >> n;
#define takean(a, n, k) \
    ll a[n + k];        \
    forn(i, n, k) cin >> a[i];
#define ll long long int
#define vi vector<long long int>
#define vvi vector<vector<long long int>>
#define sort(v) sort(v.begin(), v.end())
#define sortrev(v) sort(v.rbegin(), v.rend())
using namespace std;

void solve()
{
    ll num;
    cin >> num;
    int values[] = {0, 1, 2, 1, 2, 3, 1, 2, 3, 2, 1, 2, 2, 2, 3, 1};

    if (num <= 15)
    {
        cout << values[num] << endl;
    }
    else if (num <= 30 && num >= 16)
    {
        if (num == 20)
        {
            cout << 2 << endl;
        }
        else if (num == 23)
        {
            cout << 3 << endl;
        }
        else
        {
            cout << num / 15 + values[num % 15] << endl;
        }
    }
    else
    {
        int ans[] = {0, 1, 2, 1, 2, 1, 1, 2, 2, 2, 1, 2, 2, 2, 3};
        cout << num / 15 + ans[num % 15] << endl;
    }
}

int main()
{

    int t;
    cin >> t;
    while (t--)

    {
        solve();
    }
    return 0;
}