#include<bits/stdc++.h>
using namespace std;

int solveMem(int n, int k, vector<int> &dp)
{
    if(n==1)
        return k;

    if(n == 2)
        return k+k*(k-1);

    if(dp[n] != -1)
        return dp[n];

    dp[n] = solveMem(n-2, k, dp)*(k-1) + solveMem(n-1, k, dp)*(k-1);
    return dp[n];
}

int solveTab(int n, int k)
{
    vector<int> dp(n+1, 0);
    dp[1] = k;
    dp[2] = k+k*(k-1);

    for(int i = 3; i<=n; i++)
    {
        dp[i] = dp[i-2]*(k-1) + dp[i-1]*(k-1);
    }
    return dp[n];
}

int solveSO(int n, int k)
{
    int prev2 = k;
    int prev1 = k+k*(k-1);

    for(int i = 3; i<=n; i++)
    {
        int ans = prev2*(k-1) + prev1*(k-1);
        prev2 = prev1;
        prev1 = ans;
    }
    return prev1;
}

int numberOfWays(int n, int k)
{
    vector<int> dp;
    return solveMem(n, k, dp);
}

int main(){


    return 0;
}