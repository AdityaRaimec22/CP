#include<bits/stdc++.h>
using namespace std;

int solveMem(int n, vector<int> &dp)
{
    if(n == 0)
        return 0;

    if(dp[n] != -1)
        return dp[n];

    int ans = n;
    for(int i = 0; i*i <= n; i++)
    {
        int temp = i*i;
        ans = min(ans, 1+solveMem(n-temp, dp));
    }

    dp[n] = ans;
    return dp[n];
}

int solveTab(int n)
{
    vector<int> dp(n+1, 0);

    dp[0] = 0;

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j*j <= n; j++)
        {
            int temp = j*j;

            if(i-temp)
                dp[i] = min(dp[i], 1 + dp[i-temp]);
        }
    }
    return dp[n];
}

int minSquare(int n)
{
    vector<int> dp(n+1, -1);
    return solveMem(n, dp);
}

int main(){


    return 0;
}