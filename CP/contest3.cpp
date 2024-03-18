#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define f(i, j, n) for (int i = j; i < n; i++)
#define fo(i, j) for (auto i : j)
#define vec vector<int>
void solve() {
    int n;
        cin >> n;

        string a;
        cin >> a;

        int val = 0;

        for (int iterator = 0; iterator < n; iterator++)
        {
            if (a.substr(iterator, 3) == "map" || a.substr(iterator, 3) == "pie")
                val++;

            if (a.substr(iterator, 5) == "mapie")
                val--;
        }

        cout << val << endl;
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