#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){

    ll t;
    cin >> t;
    while(t--)
    {
        ll n, m;
        cin >> n >> m;
        vector<ll> v1;
        vector<ll> v2;
        ll odd_sum = 0;
        for(ll i = 0; i < n; i++)
        {
            int a1;
            cin >> a1;
            v1.push_back(a1);
        }

        for(int i = 0; i < m; i++)
        {
            int b1;
            cin >> b1;
            v2.push_back(b1);
        }

        sort(v1.begin(), v1.end());
        sort(v2.begin(), v2.end(), greater<ll>());

        ll a = 1, b = 1, c = v1.size(), d = v2.size();

        bool run = true;
        ll sum = 0;

        while(run)
        {
            if(n%2 == 0)
            {
                sum += v2[a-1] - v1[b-1] + v1[c-1] - v2[d-1];
                if(a*2 == n)
                {
                    run = false;
                }
                a++;
                b++;
                c--;
                d--;
            }
            else
            {
                sum += v2[a-1] - v1[b-1] + v1[c-1] - v2[d-1];
                if(a*2+1 == n)
                {
                    run = false;
                    odd_sum = max(v2[a]-v1[b], v1[c]-v2[d]);
                    sum = sum + odd_sum;
                }
                a++;
                b++;
                c--;
                d--;
            }
        }

        cout << sum << endl;

    }

    return 0;
}