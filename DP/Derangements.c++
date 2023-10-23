#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define MOD 100000007

ll solveMem(int n, vector<ll> &dp)
{
    if(n == 1)
    {
        return 0;
    }

    if(n == 2)
    {
        return 1;
    }

    if(dp[n] != -1)
    {
        return dp[n];
    }

    dp[n] = (n-1)*(solveMem(n-1, dp), solveMem(n-2, dp));
    
    return dp[n];
}

ll solveTab(int n)
{
    vector<ll> dp(n+1, 0);
    dp[1] = 0;
    dp[2] = 1;

    for (int i = 3; i <= n; i++)
    {
        ll first = dp[i-1]%MOD;
        ll second = dp[i-2]%MOD;
        ll sum = (first + second)%MOD;

        ll ans = ((i-1)*sum)%MOD;
        dp[i] = ans;
    }

    return dp[n];
    
}

ll countDerangements(int n)
{
    vector<ll> dp(n+1, -1);
    return solveMem(n+1, dp);
}

int main(){

    cout << solveTab(3) << endl;

    return 0;
}