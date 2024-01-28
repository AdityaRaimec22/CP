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
    ll p = 0;
    ll count_odd = 0;
    vec v(n);

    f(i,0,n)
    {
        cin >> v[i];
        p += v[i];
        if(v[i]&1) count_odd++;
        if(i==0)
        {
            cout<<p<<" ";
            continue;
        }
        if(count_odd%3==1)
        {
            cout << p-(count_odd)/3-1 << " ";
        } else {
            cout << p-(count_odd)/3 << " ";
        } 
    }
    cout << endl;
}

int main(){

    ll t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}