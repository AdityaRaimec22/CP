#include<bits/stdc++.h>
using namespace std;

bool solve(int index, int *arr, int n, int target)
{
    //base case
    if(index >= n)
        return 0;

    if(target < 0)
        return 0;

    if(target == 0)
        return 1;   

    bool incl = solve(index+1, arr, n, target - arr[index]);
    bool excl = solve(index+1, arr, n, target-0);

    return incl or excl;
}

bool solveMem(int index, int *arr, int n, int target, vector<vector<int> > dp)
{
    //base case
    if(index >= n)
        return 0;

    if(target < 0)
        return 0;

    if(target == 0)
        return 1;

    if(dp[index][target] != -1) 
        return dp[index][target];

    bool incl = solveMem(index+1, arr, n, target - arr[index], dp);
    bool excl = solveMem(index+1, arr, n, target-0, dp);

    return dp[index][target] = incl or excl;
}

bool solveTab(int n, int *arr, int t)
{
    int index = 0;
    vector<vector<int> > dp(n+1, vector<int> (t+1, 0));
    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = 1;
    }

    for(int index = n-1; index >= 0; index--)
    {
        for (int target = 0; target <= t; target++)
        {
            bool incl = 0;
            if(target - arr[index])
                incl = dp[index+1][target-arr[index]];

            bool excl = dp[index+1][target];
            dp[index][target] = incl or excl;
        }
    }
    return dp[0][t];
}

bool solveSO(int n, int *arr, int t)
{
    int index = 0;
    vector<int> curr(t+1, 0);
    vector<int> next(t+1, 0);
    curr[0] = 1;
    next[0] = 1;

    for(int index = n-1; index >= 0; index--)
    {
        for (int target = 0; target <= t; target++)
        {
            bool incl = 0;
            if(target - arr[index])
                incl = next[target-arr[index]];

            bool excl = next[target];
            curr[target] = incl or excl;
        }
    }
    return next[t];
}

int equalPartition(int n, int arr[])
{
    int total = 0;
    for (int i = 0; i < n; i++)
    {
        total += arr[i];
    }

    if(total & 1)
        return 0;

    int target = total/2;

    // return solve(0, arr, n, target);

    vector<vector<int> > dp(n+1, vector<int> (target+1, -1));

    return solveMem(0, arr, n, target, dp);
    
}

int main(){


    return 0;
}