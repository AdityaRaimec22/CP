#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define f(i,j,n) for(ll i=j; i<n; i++)
#define fo(i,j) for(auto i: j)
#define vec vector<ll>

void solve() {
    ll n,m,k;
    cin >> n >> m >> k;
    if(k > 3) {
        cout << 0 << endl;
        return;
    }
    if(k == 1) {
        cout << 1 << endl;
        return;
    }
    if(k == 2) {
        if(m >= n) {
            cout << m/n + n-1 << endl;
            return;
        }
        else {
            cout << m << endl;
            return;
        }
    }
    if(m <= n){
        cout << 0 << endl;
        return;
    } else {
        cout << m-n-(m/n)+1 << endl;
        return;
    }
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