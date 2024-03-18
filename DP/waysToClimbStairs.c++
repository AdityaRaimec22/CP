#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define f(i,j,n) for(int i=j; i<n; i++)
#define fo(i,j) for(auto i: j)
#define vec vector<int>

int solve(int nStairs, int i, vec dp)
{
    if(i == nStairs)
    {
        return 1;
    }

    if(i > nStairs)
    {
        return 0;
    }

    if(dp[i] != -1)
    {
        return dp[i];
    }

    return dp[i] = solve(nStairs, i+1, dp) + solve(nStairs, i+2, dp);
}

int maxWays(int nStairs)
{
    int i = 0;
    vec dp(nStairs, -1);
    return solve(nStairs, i, dp);
}

int main(){


    return 0;
}