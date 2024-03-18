#include<bits/stdc++.h>
using namespace std;
#define int long long
#define f(i,j,n) for(int i=j; i<n; i++)
#define fo(i,j) for(auto i: j)
#define vec vector<int>

void solve() {
    int x, y, n;
    cin >> n>> x >> y;
    vec v(n);
    f(i,0,n) {
        cin >> v[i];
    }

    int count = 0;
    map<int, map<int, int> > mp;

    f(i,0,n) {
        count += mp[(x-v[i]%x)%x][v[i]%y];
        mp[v[i]%x][v[i]%y]++;
    }
    cout << count << endl;
}

signed main(){

    int t;
    cin >> t;

    while (t--)
    {
        solve();
    }
    

    return 0;
}