#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define all(x) x.begin(),x.end()
#define w(t) ll t; cin>>t; while(t--)
#define f(start,n) for (int i = start; i < n; i++)
#define fr(n,start) for (int i = n-1; i >= start; i--)
int main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    w(t){
        int n; cin>>n;
        vector<int> v(n);
        f(0,n)v[i]=i+1;
        // for (auto x: v){
        //     cout<<x<<" ";
        // } cout<<endl;
        int ans = 0;
        f(0,n){
            vector<int> vv(n);
            vv = v;
            reverse(vv.begin()+i,vv.end());
            int sum = 0;
            for (int j = 0; j < n; j++){
                vv[j]=vv[j]*(j+1);
                sum += vv[j];
            }
            int mx = *max_element(all(vv));
            sum -= mx;
            ans = max(ans,sum);
        }
        cout<<ans<<endl;
    }
}