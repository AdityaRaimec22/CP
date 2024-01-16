#include<bits/stdc++.h>
using namespace std;



int main(){
    long long t;
    cin >> t;

    while(t--)
    {
        long long n, f, a, b;
        cin >> n >> f >> a >> b;
        long long min_time = INT_MAX;
        vector<long long> v;
        v.push_back(0);
        // bool ans = 0;

        for(long long i = 0; i < n; i++)
        {
            long long x;
            cin >> x;
            
            v.push_back(x);
        }
        
        for(long long i = 0; i < n; i++)
        {
            min_time = min((v[i+1]-v[i])*a, b);
            f = f - min_time;
        }

        if(f > 0)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }

    return 0;
}