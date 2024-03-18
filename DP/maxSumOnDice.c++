#include<bits/stdc++.h>
using namespace std;

#define in long long 

in solve(in dice, in faces, in target)
{
    //base case
    if(target<0 || (dice == 0 && target != 0) || (dice != 0 && target == 0))
    {
        return 0;
    }

    if(dice == 0 && target == 0)
        return 1;
    
    in ans = 0;
    for(int i = 1; i <= faces; i++)
    {
        ans = i + solve(dice-1, faces, target-i);
    }
    return ans;
}

in solveMem(in dice, in faces, in target, vector<vector<in> > dp)
{
    //base case
    if(target<0 || (dice == 0 && target != 0) || (dice != 0 && target == 0))
    {
        return 0;
    }

    if(dp[dice][target] != -1)
        return dp[dice][target];

    if(dice == 0 && target == 0)
        return 1;
    
    in ans = 0;
    for(int i = 1; i<=faces; i++)
    {
        ans = ans + solveMem(dice-1, faces, target-i, dp);
    }
    return dp[dice][target] = ans;
}

in solveTab(in d, in f, in t)
{
    //base case
    vector<in> prev(t+1, 0);
    vector<in> curr(t+1, 0);
    
    prev[0] = 1;

    for(int dice = 1; dice <= d; dice++)
    {
        for (int target = 1; target <= t; target++)
        {
            in ans = 0;
            for(int i = 1; i<=f; i++)
            {
                if(target-i >= 0)
                    ans = ans + prev[target-i];
            }
            curr[target] = ans;
        }
    }
    return prev[t];
}

in noOfWays(in m, in n, in x)
{

    // return solve(n, m, x);
    vector<vector<in> > dp(n+1, vector<in> (x+1, -1));
    return solveMem(m, n, x, dp);
}

int main(){


    return 0;
}