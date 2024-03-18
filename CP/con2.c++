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
        sum += v[i];
    }

    if(sum%3 == 0) {
        cout << 0 << endl;
        return;
    }

    if((sum+1)%3 == 0) {
        cout << 1 << endl;
        return;
    }

    if(sum == 1) {
        cout << 1 << endl;
        return;
    }

    f(i,0,n) {
        // int remainder = v[i]%3;
        int newSum = sum - v[i];
        if(newSum%3 == 0) {
            cout << 1 << endl;
            return;
        }
    }

    cout << 2 << endl;
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