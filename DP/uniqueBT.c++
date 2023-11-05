#include<bits/stdc++.h>
using namespace std;

int solveTab(int n)
{
    vector<int> dp(n+1, 0);
    dp[0] = 1;
    dp[1] = 1;

    int ans = 0;
    for (int i = 2; i <= n; i++)
    {
        for(int j = 1; j <= i; j++)
        {
            ans += dp[j-1] * dp[j-i];
        }
    }
    return ans;
}

int numsTreeMem(int n, vector<int> &dp)
{
    if(n <= 1)
        return 1;

    if(dp[n] != -1)
        return dp[n];

    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        ans += numsTreeMem(i-1, dp) * numsTreeMem(n-i, dp);
    }
    return dp[n] = ans;
}

int numTrees(int n)
{
    if(n <= 1)
        return 1;

    int ans = 0;
    for(int i = 1; i <= n; i++)
    {
        ans += numTrees(i-1) * numTrees(n-i);
    }
    return ans;
}

int main()
{

}