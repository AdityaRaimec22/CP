#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define f(i,j,n) for(ll i=j; i<n; i++)
#define fo(i,j) for(auto i: j)
#define vec vector<ll>

void solve() {
    int n;
    cin >> n;
    vector<vector<char> > s(n+1, vector<char>(n+1));

    int count = 1;

    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < n; j++) {
            cin >> s[i][j];
        }
    } 

    cout << s[0][0];
    for(int i = 0; i < n-1; i++) {

        if(s[0][i+1] == s[1][i]) {
            cout << s[0][i+1];
            continue;
        }

        cout << '0';
        
    }

    cout << s[1][n-1] << endl;

    for(int i = 1; i < n-1; i++) {
        if(s[0][i] == s[1][i-1]) {
            count++;
        }
        else
        {
            if(s[0][i] == '0')
            {
                count = 1;
            }
        }
    }

    if(s[0][n-1] == s[1][n-2]) {
        count ++;
    }
    cout << count << endl;
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