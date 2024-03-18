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
    f(i,0,n) {
        cin >> v[i];
    }

    vec ans;
    f(i,0,n) {
        if(v[i] < 10) {
            ans.push_back(v[i]);
        } else {
         
            int num = v[i];
            stack<int> s;
            while (num != 0)
            {
                s.push(num%10);
                num = num/10;
            }
            while (!s.empty())
            {
                int top = s.top();
                s.pop();
                ans.push_back(top);
            }
        } 
    }

    f(i,0,ans.size()) {
        if(ans[i] > ans[i+1]) {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
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