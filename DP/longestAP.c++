#include<bits/stdc++.h>
using namespace std;

int solve(int index, int difference, int a[])
{
    if(index < 0)
        return 0;

    int ans = 0;
    for(int j = index - 1; j >= 0; j--)
    {
        if(a[index] - a[j] == difference)
        {
            ans = max(ans, 1+solve(j, difference, a));
        }
    }
    return ans;
}

int solveMem(int index, int difference, int a[], unordered_map<int, int> dp[])
{
    if(index < 0)
        return 0;

    if(dp[index].count(difference))
        return dp[index][difference];

    int ans = 0;
    for(int j = index - 1; j >= 0; j--)
    {
        if(a[index] - a[j] == difference)
        {
            ans = max(ans, 1+solve(j, difference, a));
        }
    }
    return dp[index][difference] = ans;
}

int solveTab(int n, int a[])
{
    if(n <= 2)
        return n;

    int ans = 0;

    unordered_map<int, int> dp[n+1];

    for(int i = 1; i<n; i++)
    {
        for(int j = 0; j<i; j++)
        {
            int diff = a[i] - a[j];
            int cnt = 1;

            if(dp[j].count(diff))
                cnt = dp[j][diff];

            dp[i][diff] = 1 + cnt;
            ans = max(ans, dp[i][diff]);
        }
    }
    return ans;
}

int longestApWithGivenDifference(vector<int> &arr, int d)
{
    unordered_map<int, int> dp;
    int ans = 0;

    for(int i = 0; i < arr.size(); i++)
    {
        int temp = arr[i] - d;
        int tempAns = 0;

        if(dp.count(temp))
            tempAns = dp[temp];
        
        //current answer update
        dp[arr[i]] = 1 + tempAns;

        //ans update
        ans = max(ans, dp[arr[i]]);
    }
    return ans;
}

int lengthOfLongestAP(int a[], int n)
{
    if(n <= 2)
    {
        return n;
    }

    int ans = 0;

    for(int i = 0; i < n; i++)
    {
        for(int j = i+1; j<n; j++)
        {
            ans = max(ans, 2+solve(i, a[i] - a[j], a));
        }
    }
    
    return ans;
}

int main(){


    return 0;
}