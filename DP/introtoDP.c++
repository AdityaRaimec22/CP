#include<bits/stdc++.h>
using namespace std;

int fib(int n, vector<int> dp)
{
    //step 1: base case
    if(n<=1)
        return n;
    
    // step 2
    if(dp[n] != -1)
        return dp[n];

    //step 3
    dp[n] = dp[n-1] + dp[n-2];
    return dp[n];
}

int main(){

    int n;
    cin >> n;

    //step 1
    vector<int> dp(n+1);

    for (int i = 0; i <= n; i++)
    {
       dp[i] = -1;
    }

    cout << fib(n, dp) << endl;
    

    return 0;
}