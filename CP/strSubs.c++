#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define f(i, j, n) for (int i = j; i < n; i++)
#define fo(i, j) for (auto i : j)
#define vec vector<int>

int main()
{

    int t;
    cin >> t;

    while (t--)
    {
        int n, k;
        cin >> n >> k;
        int a = 97;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < k; j++)
            {
                cout << char(a + j);
            }
        }
        cout << endl;
    }

    return 0;
}