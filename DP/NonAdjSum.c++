#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define f(i,j,n) for(int i=j; i<n; i++)
#define fo(i,j) for(auto i: j)
#define vec vector<int>

int solve(vec &nums, int n, vec dp)
{
    if(n == 0)
    {
        return nums[0];
    }

    if(n < 0)
    {
        return 0;
    }

    if(dp[n] != -1)
    {
        return dp[n];
    }

    int incl = solve(nums, n-2, dp) + nums[n];
    int excl = solve(nums, n-1, dp);

    return max(incl, excl);
}

int maxNonAdjSum(vec &nums)
{
    int size = nums.size();
    vec dp(size+1, -1);
    return solve(nums, size, dp);
}

int main(){


    return 0;
}