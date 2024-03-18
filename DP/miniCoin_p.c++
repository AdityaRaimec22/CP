#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define f(i,j,n) for(int i=j; i<n; i++)
#define fo(i,j) for(auto i: j)
#define vec vector<int>

int solveTab(vec &num, int x)
{
    
}

int solve(vector<int> &num, int x, int size, vec dp) {

    if(x == 0)
    {
        return 0;
    }

    if(x < 0)
    {
        return INT_MAX;
    }

    if(dp[x] != -1)
    {
        return dp[x];
    }

    int mini = INT_MAX;
    for(int i = 0; i < size; i++)
    {
        int ans = solve(num, x-num[i], size, dp);
        if(ans != INT_MAX)
        {
            mini = min(mini, 1+ans);
        }
    }

    return mini;
}

int minimumElements(vector<int> &num, int x)
{
    // Write your code here.
    int size = num.size();
    vec dp(size+1, -1);
    return solve(num, x, size, dp);
}

int main(){

    vec num;
    int n; cin >> n;
    int x; cin >> x;
    f(i,0,n)
    {
        int a;
        cin >> a;
        num.push_back(a);
    }

    cout << minimumElements(num, x) << endl;

    return 0;
}