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

    

    vector<vec> m(n, vec(n, 0));
    vec v;
    int newSum = 0;
    int sum = 0;
    f(i, 0, n)
    {
        f(j, 0, n)
        {
            cin >> m[i][j];
            sum += m[i][j];
        }
    }

    if (n == 1)
    {
        cout << "YES" << endl;
        cout << 7 << endl;
        return;
    }

    f(i, 0, n)
    {
        int mum = m[i][0];
        if (i == 0)
        {
            mum = m[i][1];
        }

        f(j, 0, n)
        {
            if (m[i][j] == 0 && i == j)
            {
                continue;
            }

            mum = mum & m[i][j];
        }
        v.push_back(mum);
    }

    f(i,0,n)
    {
        newSum += v[i];
    }

    if(newSum == 0 && sum != 0)
    {
        cout << "NO";
    }
    else
    {
        cout << "YES" << endl;
        f(i,0,n)
        {
            cout << v[i] << " ";
        }
    }
    
    cout << endl;
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