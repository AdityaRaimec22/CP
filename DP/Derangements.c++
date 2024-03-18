#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define MOD 1000000007

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

    dp[n] = (n-1)*(solveMem(n-1, dp) + solveMem(n-2, dp));
    
    return dp[n];
}

ll solveNew(int n)
{
    int prev2 = 0;
    int prev1 = 1;

    for(int i = 3; i <= n; i++)
    {
        int curr = (n-1)*(prev2 + prev1);
        prev2 = prev1;
        prev1 = curr;
    }

    return prev1;
}

ll solveTab(int n)
{
    vector<ll> dp(n+1, 0);
    dp[1] = 0;
    dp[2] = 1;

    for (int i = 3; i < n; i++)
    {
        dp[i] = ((i-1)*(((dp[i-2]%MOD) + (dp[i-1]%MOD))%MOD))%MOD;
    }

    return dp[n];
}

ll countDerangements(int n)
{
    vector<ll> dp(n+1, -1);
    return solveMem(n+1, dp);
}

int main(){

    cout << solveNew(1) << endl;

    return 0;
}