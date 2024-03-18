#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define f(i,j,n) for(int i=j; i<n; i++)
#define fo(i,j) for(auto i: j)
#define vec vector<int>

int solve(int n, int x, int y, int z, vec &dp)
{
    if(n == 0)
    {
        return 0;
    }

    if(n < 0)
    {
        return INT_MIN;
    }

    if(dp[n] != -1)
    {
        return dp[n];
    }

    int a = solve(n-x, x, y, z, dp)+1;
    int b = solve(n-y, x, y, z, dp)+1;
    int c = solve(n-z, x, y, z, dp)+1;

    dp[n] = max(a, max(b,c));
    return dp[n];
}

int cutSegments(int n, int x, int y, int z) {
	// Write your code here.
    vec dp(n+1, -1);
    return solve(n, x, y, z, dp);
}

int main(){

    int n, x, y, z;
    cin >> n >> x >> y >> z;

    cout << cutSegments(n,x,y,z) << endl;

    return 0;
}