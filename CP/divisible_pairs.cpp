#include <bits/stdc++.h>
#define forn(i, n, k) for (int i = k; i < n + k; i++)
#define all(v) v.begin(), v.end()
#define take(n) ll n; cin >> n;
#define takean(a, n, k) ll a[n + k]; forn(i, n, k) cin >> a[i];
#define ll long long int
#define vi vector<long long int>
#define vvi vector<vector<long long int>>
#define sort(v) sort(v.begin(),v.end())
#define sortrev(v) sort(v.rbegin(),v.rend())
using namespace std;
int main(){
    
    int t;
    cin >> t;
    while(t--)
    {
        ll n,x,y;
        cin>>n>>x>>y;
        vi v(n);
        for(ll i=0;i<n;i++){
            cin>>v[i];
        }
        ll count=0;
        map<ll,map<ll,ll>>m;
        for(ll i=0;i<n;i++) {
            count+=m[((x-(v[i]%x))%x)][v[i]%y];
            m[v[i]%x][v[i]%y]++;   
        }
        cout<<count<<endl;
    }
    return 0;
}