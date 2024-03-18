#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define f(i,j,n) for(int i=j; i<n; i++)
#define fo(i,j) for(auto i: j)
#define vec vector<int>

void solve(){
    int n, m, k;
    cin >> n >> m >> k;
    vec v1(n), v2(m);
    f(i,0,n) {
        cin >> v1[i];
    }
    sort(v1.begin(), v1.end());
    f(i,0,m) {
        cin >> v2[i];
    }
    sort(v2.begin(), v2.end());
    // cout << "hello "<< v2[0] << endl;
    int count = 0;
    f(i,0,n) {
        // cout << v1[i] << "the value is: " << v2[0] << endl;
        if(v1[i] + v2[0] > k) {
            break;;
        }
        f(j,0,m) {
            if(v1[i]+v2[j] <= k) {
                count++;
            } else {
                break;
            }
        }
    }
    cout << count << endl;
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