#include<bits/stdc++.h>
using namespace std;

#define ll long long 

int solveMem(vector<int> &nums, int n, vector<int> dp)
{
    //base case
    if(n < 0)
        return 0;
    if(n == 0)
        return nums[0];

    if(dp[n] != -1)
        return dp[n];

    int incl = solveMem(nums, n - 2, dp) + nums[n];
    int excl = solveMem(nums, n - 1, dp) + 0;

    dp[n] = max(incl, excl);
    return dp[n];
}

ll int houseRobbery(vector<int> &valueInHouse)
{
    int n = valueInHouse.size();

    if(n == 1)
    {
        return valueInHouse[0];
    }

    vector<int> first, second;
    for (int i = 0; i < n; i++)
    {
        if(i != n-1)
        {
            first.push_back(valueInHouse[i]);
        }
        if(i != 0)
        {
            second.push_back(valueInHouse[i]);
        }
    }

    return max(solveSpaceOpt(first), solveSpaceOpt(second));
    
}

int solveSpaceOpt(vector<int> nums)
{
    int n = nums.size();

    int prev2 = 0;
    int prev1 = nums[0];

    for (int i = 0; i < n; i++)
    {
        int incl = prev2 + nums[i];
        int excl = prev1 + 0;

        int ans = max(incl, excl);
        prev2 = prev1;
        prev1 = ans;
    }

    return prev1;
    
}

int maxAdjSum(vector<int> &nums)
{
    vector<int> dp(nums.size(), -1);
    return solveMem(nums, nums.size(), dp);
}

int main(){


    return 0;
}