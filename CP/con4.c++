#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define f(i, j, n) for (int i = j; i < n; i++)
#define fo(i, j) for (auto i : j)
#define vec vector<int>

void solve()
{
    int n;
    cin >> n;
    vec v(n);

    int oneCount = 1;

    f(i, 0, n)
    {
        cin >> v[i];
    }

    bool exist = false;

    sort(v.begin(), v.end());

    f(i, 1, n)
    {
        if (v[0] == v[i])
        {
            oneCount++;
        }
        if (v[i] % v[0] != 0)
        {
            exist = true;
            break;
        }
    }

    if (oneCount == 1)
    {
        cout << "YES" << endl;
        return;
    }
    else if (oneCount > 1 && exist)
    {
        cout << "YES" << endl;
        return;
    }

    cout << "NO" << endl;
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