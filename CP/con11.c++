#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define f(i,j,n) for(ll i=j; i<n; i++)
#define fo(i,j) for(auto i: j)
#define vec vector<ll>

void solve() {
    ll n;
    cin >> n;

    ll ans = (ll)log2(n); // Casting the result to ll

    cout << (ll)pow(2, ans) << endl; // Casting the result of pow to ll
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