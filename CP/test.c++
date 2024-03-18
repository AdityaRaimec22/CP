#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define f(i,j,n) for(int i=j; i<n; i++)
#define fo(i,j) for(auto i: j)
#define vec vector<int>

void solve() {
    int n,a,b;cin>>n>>a>>b;
    int count = 0;

    f(i,1,n+1) {
        if(i%a == 0 && i%b == 0) {
            count++;
        }
    }

    int count2 = n/(a*b);

    cout << count2 << endl;

    cout << count << endl;
}

int main(){

    solve();

    return 0;
}