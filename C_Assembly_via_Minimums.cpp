#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define f(i,j,n) for(int i=j; i<n; i++)
#define fo(i,j) for(auto i: j)
#define vec vector<int>

void solve() {
    int n;
    cin >> n;
    int val = (n*(n-1))/2;
    vec v(val);
    f(i,0,val) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    vec ans(n);
    int adder = n-1;
    int start = 0;
    f(i,0,n-1) {
        ans[i] = v[start];
        start += adder;
        adder--;
    }
    ans[n-1] = ans[n-2];

    f(i,0,n) {
        cout << ans[i] <<" ";
    }cout << endl;
}

int main(){

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}