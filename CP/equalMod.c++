#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define f(i,j,n) for(int i=j; i<n; i++)
#define fo(i,j) for(auto i: j)
#define vec vector<ll>



int main(){
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, res = 2;
        cin >> n;
        vec v(n);
        
        f(i,0,n)
        {
            cin >> v[i];
        }

        while (1)
        {
            set<ll> remainder;
            f(i,0,n)
            {
                remainder.insert(v[i]%res);
            }
            if(remainder.size() == 2)
                break;
            res *= 2;
        }
        cout << res << endl;
    }
    

    return 0;
}