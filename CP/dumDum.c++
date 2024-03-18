#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define f(i,j,n) for(ll i=j; i<n; i++)
#define fo(i,j) for(auto i: j)
#define vec vector<ll>

void solve()
{   
    ll n;
    cin >> n;
    vec a(n), b(n);
    f(i,0,n)
    {
        cin >> a[i];
    }
    f(i,0,n)
    {
        cin >> b[i];
    }

    map<int, int> mp;
    f(i,0,n)
    {
        mp[a[i]] = b[i];
    }

    fo(i,mp)
    {
        cout << i.first << " ";
    }
    cout << endl;
    fo(i,mp)
    {
        cout << i.second << " ";
    }
    cout << endl;
}

int main(){

    ll t;
    cin >> t;

    while (t--)
    {
        solve();
    }
    

    return 0;
} 