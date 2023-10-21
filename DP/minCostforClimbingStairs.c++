#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> &cost, int n, vector<int> &dp)
{
    if(n==0 || n==1)
    {
        return cost[n];
    }

    //step 3: if dp[n] has other value than -1 then return it.
    if(dp[n] != -1)
    {
        return dp[n];
    }

    dp[n] = cost[n] + min(solve(cost, n-1, dp), solve(cost, n-2, dp));
    return dp[n];
}

int solve2(vector<int> &cost, int n)
{
    vector<int> dp(n+1);

    dp[0] = cost[0];
    dp[1] = cost[1];

    for(int i = 2; i < n; i++)
    {
        dp[i] = cost[i] + min(dp[i-1], dp[i-2]);
    }

    return min(dp[n-1], dp[n-2]);
}

int solve3(vector<int> &cost, int n)
{
    int prev2 = cost[0];
    int prev1 = cost[1];

    for(int i = 2; i < n; i++)
    {
        int curr = cost[i] + min(prev1, prev2);
        prev2 = prev1;
        prev1 = curr;
    }

    return min(prev1, prev2);
}

int minCostClimbingStairs(vector<int> &cost)
{
    int n = cost.size();
    //step 1: initialize dp vector
    // vector<int> dp(n+1, -1);
    // int ans = min(solve(cost, n-1, dp), solve(cost, n-1, dp));
    // return ans;

    //by tabulation
    // return solve2(cost, n);

    //by variables
    return solve3(cost, n);
}

int main(){

    int n;
    cin>>n;
    vector<int> cost(n);

    for(int i = 0; i < n; i++)
    {
        cin >> cost[i];
    }

    cout << minCostClimbingStairs(cost) << endl;

    return 0;
}   