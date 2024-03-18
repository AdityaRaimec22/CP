#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define f(i,j,n) for(int i=j; i<n; i++)
#define fo(i,j) for(auto i: j)
#define vec vector<int>

class Solution{
    private:
    int solve(int m, int n, int x, vector<vec> dp) {
        if(x < 0 || (x == 0 && m != 0) || (m == 0 && x != 0))
        {
            return 0;
        }

        if(x == 0 && m == 0) {
            return 1;
        }
        if(dp[m][n] != -1) {
            return dp[m][n];
        }

        int ans = 0;
        f(i,1,n+1) {
            ans = ans + solve(m-1, n, x-i, dp);
        }

        return dp[m][n] = ans;
    }

    int solveTab(int m, int n, int x) {

        // vector<vec> dp(m+1, vec(x+1, 0));
        vec currRow(x+1, 0);
        vec nextRow(x+1, 0);
        currRow[0] = 1;

        f(i,1,m+1) {
            f(j,1,x+1) {
                int ans = 0;
                f(k,1,n+1) {
                    if(j-k >= 0)
                        ans = ans + currRow[j-k];
                }
                nextRow[j] = ans;
            }
            currRow = nextRow;
        }

        return currRow[x];
    }
    public:
    ll noOfWays(int m, int n, int x) {
        vector<vec> dp(n+1, vec(x+1, -1));
        return solveTab(n, m, x);
    }
};

int main(){
    Solution s;
    cout << s.noOfWays(6, 3, 12) << endl;

    return 0;
}