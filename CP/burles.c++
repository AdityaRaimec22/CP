#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define f(i, j, n) for (int i = j; i < n; i++)
#define fo(i, j) for (auto i : j)
#define vec vector<int>

void solve()
{
    int n, k, a, b;
    cin >> n >> k >> a >> b;

    int remainder = n % 3;

    if ((b * k >= n - remainder && a >= remainder) || a == n - b * k)
    {
        cout << 0 << endl;
        return;
    }

    if (n - b * k > 0)
    {
        n = n - b * k - a;
    }
    else
    {
        cout << remainder - a << endl;
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