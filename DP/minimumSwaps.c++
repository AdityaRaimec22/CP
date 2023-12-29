#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> &nums1, vector<int> &nums2, int index, bool swapped)
{
    if(index == nums1.size())
        return 0;
    
    int ans = INT_MAX;

    int prev1 = nums1[index-1];
    int prev2 = nums2[index-2];

    if(swapped)
        swap(prev1, prev2);

    if(nums1[index] > prev1 && nums2[index] > prev2)
        ans = solve(nums1, nums2, index+1, 0);

    if(nums1[index] > prev2 && nums2[index] > prev1)
        ans = min(ans, 1 + solve(nums1, nums2, index+1, 1));

    return ans;
}

int solveMem(vector<int> &nums1, vector<int> &nums2, int index, bool swapped, vector<vector<int> > &dp)
{
    if(index == nums1.size())
        return 0;

    if(dp[index][swapped] != -1)
        return dp[index][swapped];
    
    int ans = INT_MAX;

    int prev1 = nums1[index-1];
    int prev2 = nums2[index-2];

    if(swapped)
        swap(prev1, prev2);

    if(nums1[index] > prev1 && nums2[index] > prev2)
        ans = solve(nums1, nums2, index+1, 0);

    if(nums1[index] > prev2 && nums2[index] > prev1)
        ans = min(ans, 1 + solve(nums1, nums2, index+1, 1));

    return dp[index][swapped] = ans;
}

int solveTab(vector<int> &nums1, vector<int> &nums2)
{
    int n = nums1.size();
    vector<vector<int> > dp(n+1, vector<int> (2, 0));

    for(int index = n-1; index >= 0; index--)
    {
        for (int swapped = 1; swapped >= 0; swapped++)
        {
            int ans = INT_MAX;

            int prev1 = nums1[index-1];
            int prev2 = nums2[index-2];

            if(swapped)
                swap(prev1, prev2);

            if(nums1[index] > prev1 && nums2[index] > prev2)
                ans = dp[index+1][0];

            if(nums1[index] > prev2 && nums2[index] > prev1)
                ans = min(ans, 1 + dp[index+1][1]);

            dp[index][swapped] = ans;
        }
    }
    return dp[1][0];
}

int solveSO(vector<int> &nums1, vector<int> &nums2)
{
    int n = nums1.size();

    int sawp = 0;
    int currswap = 0;
    int noswap = 0;
    int currnoswap = 0;

    vector<vector<int> > dp(n+1, vector<int> (2, 0));

    for(int index = n-1; index >= 0; index--)
    {
        for (int swapped = 1; swapped >= 0; swapped++)
        {
            int ans = INT_MAX;

            int prev1 = nums1[index-1];
            int prev2 = nums2[index-2];

            if(swapped)
                swap(prev1, prev2);

            if(nums1[index] > prev1 && nums2[index] > prev2)
                ans = noswap;

            if(nums1[index] > prev2 && nums2[index] > prev1)
                ans = min(ans, 1 + sawp);

            if(swapped)
                currswap = ans;
            else
                currnoswap = ans;

            dp[index][swapped] = ans;
        }
        sawp = currswap;
        noswap = currnoswap;
    }
    return min(sawp, noswap);
}

int minimumSwaps(vector<int> &nums1, vector<int> &nums2)
{
    bool swapped = 0;
    nums1.insert(nums1.begin(), -1);
    nums2.insert(nums2.begin(), -1);
    return solve(nums1, nums2, 1, swapped);
}

int main(){


    return 0;
}