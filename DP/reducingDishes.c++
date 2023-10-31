#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> &satisfaction, int index, int time)
{
    if(index == satisfaction.size())
        return 0;

    int include = satisfaction[index] * (time+1) + solve(satisfaction, index+1, time+1);
    int exclude = 0 + solve(satisfaction, index+1, time);

    return max(include, exclude);
}

int solveMem(vector<int> &satisfaction, int index, int time, vector<vector<int> > dp)
{
    if(index == satisfaction.size())
        return 0;

    if(dp[index][time] != -1)
        return dp[index][time];

    int include = satisfaction[index] * (time+1) + solveMem(satisfaction, index+1, time+1, dp);
    int exclude = 0 + solveMem(satisfaction, index+1, time, dp);

    dp[index][time] = max(include, exclude);
    return dp[index][time];
}

int solveTab(vector<int> &satisfaction)
{
    int index = 0;
    int time = 0;
    int n = satisfaction.size();
    vector<vector<int> > dp(n+1, vector<int> (n+1, 0));

    for(index = n-1; index>=0; index--)
    {
        for(time = index; time>=0; time--)
        {
            int include = satisfaction[index] * (time+1) + dp[index+1][time+1];
            int exculde = 0 + dp[index+1][time];

            dp[index][time] = max(include, exculde);
        }
    }
    return dp[0][0];
}

int solveSO(vector<int> &satisfaction)
{
    int index = 0;
    int time = 0;
    int n = satisfaction.size();
    vector<int> curr(n+1, 0);
    vector<int> next(n+1, 0);

    for(index = n-1; index>=0; index--)
    {
        for(time = index; time>=0; time--)
        {
            int include = satisfaction[index] * (time+1) + next[time+1];
            int exculde = 0 + next[time];

            curr[time] = max(include, exculde);
        }
        next = curr;
    }
    return next[0];
}

int satisfaction(vector<int> &satisfaction)
{
    sort(satisfaction.begin(), satisfaction.end());
    // return solve(satisfaction, 0, 0);
    int n = satisfaction.size();
    vector<vector<int> > dp(n+1, vector<int> (n+1, -1));
    return solveMem(satisfaction, 0, 0, dp);
}

int main(){


    return 0;
} 