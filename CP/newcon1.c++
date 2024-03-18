#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define f(i, j, n) for (ll i = j; i < n; i++)
#define fo(i, j) for (auto i : j)
#define vec vector<ll>

void solve()
{
    ll n;
    cin >> n;
    string s;
    cin >> s;
    string s2 = s;
    reverse(s2.begin(), s2.end());
    ll i = 0;
    ll j = s.length() - 1;
    // cout << i << " " << j << endl;

    // cout << "the actual answer is: " << a << " " << b << endl;

    // cout << (ll)s[i]  << " " << (ll)s[j] << endl;

    if ((ll)s[i] < (ll)s[j])
    {
        cout << s << endl;
        return;
    }
    else if ((ll)s[i] > (ll)s[j])
    {
        // cout << "me yha hu: "<< (ll)s[i] << " "<< (ll)s[j]  << endl;
        cout << s2 + s << endl;
        return;
    }

    while ((ll)s[i] == (ll)s[j] && i != s.length()/2)
    {

        i++;
        j--;
        
        // cout << "I am here" << endl;
        if ((ll)s[i] < (ll)s[j])
        {
            cout << s << endl;
            return;
        }
        else if ((ll)s[i] > (ll)s[j])
        {
            // cout << "I am here: "<< (ll)s[i] << " "<< (ll)s[j]  << endl;
            cout << s2 + s << endl;
            return;
        }

        // cout << (ll)s[i] << " " << (ll)s[j] << endl;
    }
    cout << s << endl;
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