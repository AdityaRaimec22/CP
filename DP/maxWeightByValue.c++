#include<bits/stdc++.h>
using namespace std;

int solveMem(vector<int> weight, vector<int> value, int index, int capacity, vector<vector<int> > dp)
{
    if(index == 0)

        if(weight[0] <= capacity)
            return value[0];
        else
            return 0;
    
    if(dp[index][capacity] != -1)
        return dp[index][capacity];
    
    int include = 0;
    if(weight[index] <= capacity)
        include = value[index] + solveMem(weight, value, index-1, capacity - weight[index], dp);
    
    int exclude = 0 + solveMem(weight, value, index-1, capacity - weight[index], dp);

    dp[index][capacity] = max(exclude, include);
    return dp[index][capacity];
}

int solveTab(vector<int> weight, vector<int> value, int n, int maxWeight)
{
    vector<vector<int> > dp(n, vector<int>(maxWeight+1, -1));
    for(int w = weight[0]; w <= maxWeight; w++)
    {
        if(weight[0] <= maxWeight)
            dp[0][w] = value[0];
        else
            dp[0][w] = 0;
    }

    for(int index = 1; index<n; index++)
    {
        for (int w = 0; w <= maxWeight; w++)
        {
            int include = 0;

            if(weight[include] <= w)
                include = value[index] + dp[index-1][w-weight[index]];

            int exclude = 0 + dp[index-1][w];

            dp[index][w] = max(exclude, include);
        }
    }

    return dp[n-1][maxWeight];
}

int solveSO(vector<int> &weight, vector<int> &value, int n, int capacity)
{
    vector<int> prev(capacity+1, 0);
    vector<int> curr(capacity+1, 0);

    for(int w = weight[0]; w <= capacity; w++)
    {
        if(weight[0] <= capacity)
            prev[w] = value[0];
        else
            prev[w] = 0;
    }

    for(int index = 1; index<n; index++)
    {
        for(int w = 0; w <= capacity; w++)
        {
            int include = 0;

            if(weight[index] <= w)
                include = value[index] + prev[w-weight[index]];
            
            int exclude = 0 + prev[w];

            curr[w] = max(exclude, include);
        }
        prev = curr;
    }
    return prev[capacity];
}

int knapSack(vector<int> weight, vector<int> value, int n, int maxWieght)
{
    vector<vector<int> > dp(n, vector<int>(maxWieght+1, -1));
    return solveMem(weight, value, n, maxWieght, dp);
}

int main(){


    return 0;
} 