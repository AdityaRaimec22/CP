#include<bits/stdc++.h>
using namespace std;

int solve(int index, int buy, vector<int> &prices)
{
    if(index == prices.size())
        return 0;

    int profit = 0;
    if(buy)
    {
        int buyKaro = -prices[index] + solve(index+1, 0, prices);
        int skipKaro = 0 + solve(index+1, 1, prices);
        profit += max(buyKaro, skipKaro);
        // cout << "The profit is: " << profit << endl;
    }
    else
    {
        int sellKaro = prices[index] + solve(index+1, 1, prices);
        int skipKaro = 0 + solve(index+1, 0, prices);
        profit += max(sellKaro, skipKaro);
        // cout << "The profit is: " << profit << endl;
    }
    return profit;
}

//solveMem is similar process done before.

int solveTab(vector<int> &prices)
{
    int n = prices.size();
    vector<vector<int>> dp(n+1, vector<int> (2, 0));

    for(int index = n-1; index >= 0; index--)
    {
        for(int buy = 0; buy <= 1; buy++)
        {
            int profit = 0;
            if(buy)
            {
                int buyKaro = -prices[index] + dp[index+1][0];
                int skipKaro = 0 + dp[index+1][1];
                profit = max(buyKaro, skipKaro);
            }
            else
            {
                int sellKaro = prices[index] + dp[index+1][1];
                int skipKaro = 0 + dp[index+1][0];
                profit = max(sellKaro, skipKaro);
            }
            dp[index][buy] = profit;
        }
    }
    return dp[0][1];
}

int genMaxProfit(vector<int> &prices)
{
    return solve(0, 1, prices);
}

int main()
{
    vector<int> prices(3, 0);
    for (int i = 0; i < 3; i++)
    {
        cin >> prices[i];
    }
    int ans = genMaxProfit(prices);

    cout << " The max profit is: " << ans << endl;
    
}