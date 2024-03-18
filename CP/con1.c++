#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define f(i,j,n) for(int i=j; i<n; i++)
#define fo(i,j) for(auto i: j)
#define vec vector<int>

void solve() {
    int n;
    cin >> n;
    vec v(n);
    f(i,0,n) {
        cin >> v[i];
    }

    int sum = 0;
    f(i,0,n) {
        sum += abs(v[i]);
    }

    cout << sum << endl;
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