#include<bits/stdc++.h>
using namespace std;
#define int long long
#define f(i,j,n) for(int i=j; i<n; i++)
#define fo(i,j) for(auto i: j)
#define vec vector<int>

void solve() {

    int n;
    cin >> n;
    vec v(n);
    int count = 0;
    f(i,0,n) {
        cin >> v[i];
        if(v[i] != v[0]) {
            count++;
        }
    }

    int q;
    cin >> q;

    vector<int> dp(n+1, -1);
    f(i,0,n) {
        f(j,i+1,n) {
            if(v[i] != v[j]) {
                dp[i+1] = j+1;
                break;
            }
        }
    }

    f(i,0,q) {
        int a, b;
        cin >> a >> b;
        if(b < dp[a] || dp[a] == -1 ) {
            cout << -1 <<" "  << -1 << endl;
        } else {
            cout << a << " " << dp[a] << endl;
        }
    }
}

signed main(){

    int t;
    cin >> t;

    while (t--)
    {
        solve();
        cout << endl;
    }

    return 0;
}