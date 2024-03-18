#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
#define ll long long
#define f(i,j,n) for(int i=j; i<n; i++)
#define fo(i,j) for(auto i: j)
#define vec vector<int>

pair<int, int> findMax(vec &a) {
    int ans = INT_MIN;
    int index = 0;
    f(i,0,a.size()) {
        if(a[i] > ans) {
            ans = a[i];
            index = i;
        }
    }
    pair<int, int> p = make_pair(ans, index);
    return p;
}

pair<int, int> findMin(vec &b) {
    int ans = INT_MAX;
    int index = 0;
    f(i,0,b.size()) {
        if(b[i] < ans) {
            ans = b[i];
            index = i;
        }
    }
    pair<int, int> p = make_pair(ans, index);
    return p;
}

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vec a(n), b(m);
    f(i,0,n) {
        cin >> a[i];
    }
    f(i,0,m) {
        cin >> b[i];
    }
    if(k%2 == 0 && k>2) {
        k=2;
    }
    if(k%2 != 0 && k>3) {
        k = 3;
    }
    while (k--)
    {
        if(k%2 != 0)
        {
            f(i,0,n) {
                cout << a[i] << " ";
            }
            cout << endl;
            swap(a[findMin(a).second], b[findMax(b).second]);
            f(i,0,n) {
                cout << a[i] << " ";
            }
            cout << endl;
        } else {
            swap(b[findMin(a).second], a[findMax(b).second]);
        }
    }
    int maxSum = 0;
    f(i,0,n) {
        maxSum += a[i];
    }
    cout << maxSum << endl;
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