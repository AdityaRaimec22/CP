#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define f(i,j,n) for(int i=j; i<n; i++)
#define fo(i,j) for(auto i: j)
#define vec vector<int>

int solve(int n)
{
    if(n == 0)
    {
        return 0;
    }

    int ans = n;
    for(int i = 0; i*i <= n; i++)
    {
        ans = min(ans, 1+solve(n-i*i));
    }

    return ans;
}

int solveTab(int n)
{
    vector<int> dp(n+1, 0);


}

int MinSquares(int n)
{
    // Code here
    return solve(n);
}

int main(){


    return 0;
}