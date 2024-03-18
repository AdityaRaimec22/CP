#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define f(i,j,n) for(int i=j; i<n; i++)
#define fo(i,j) for(auto i: j)
#define vec vector<int>

void solve() {
    int l, m, a, b;
    cin >> l >> m >> a >> b;

    int remainder = l%m;

    if(a >= l || (b >= l/m && a >= remainder) || (b >= ((l-a)/m)+1)) {
        cout << 0 << endl;
        return;
    }

    if(b*m > l) {
        cout << remainder - a << endl;
        return;
    }

    l = l - a - b*m;
    int divisor = l/m;
    if(l%m <= m-1 && a >= l%m && l%m != 0) {
        divisor++;
        cout << divisor << endl;
        return;
    }

    cout << l/m + l%m << endl;
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