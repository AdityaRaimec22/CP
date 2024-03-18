#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define f(i,j,n) for(int i=j; i<n; i++)
#define fo(i,j) for(auto i: j)
#define vec vector<int>

void solve() {
    int n;
    cin >> n;

    if(n%2 != 0) {
        cout << "NO" << endl;
        return;
    }

    char val = 'A';
    cout << "YES" << endl;
    f(i,0,n/2){
        cout << val << val;
        val++;
    }
    cout << endl;
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