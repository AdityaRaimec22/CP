#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define f(i,j,n) for(int i=j; i<n; i++)
#define fo(i,j) for(auto i: j)
#define vec vector<int>

class Solution {
private:
    static bool Compare(const vec &a, const vec &b) {
        if(a[0] != b[0])
            return a[0] < b[0];
        else
            return a[1] > b[1];
    }

    int solve(int n, vector<vector<int>>& envelopes, int curr, int prev, vector<vec> &dp) {

        if(curr == n) {
            return 0;
        }

        if(dp[curr][prev+1] != -1) {
            return dp[curr][prev+1];
        }

        //include
        int take = 0;
        if(prev == -1 || envelopes[prev][1] < envelopes[curr][1]) {
            take = 1 + solve(n, envelopes, curr+1, curr, dp);
        }

        //exclude
        int notTake = 0 + solve(n, envelopes, curr+1, prev, dp);

        cout << "take: " << take << "notTake: " << notTake << endl;
 
        return dp[curr][prev+1] = max(take, notTake);
    }

public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(), Compare);
        int curr = 0;
        int prev = -1;
        int n = envelopes.size();
        vector<vec> dp(n+1, vec(n+1, -1));
        return solve(n, envelopes, prev, curr, dp);
    }
};

int main(){

    Solution s;
    vector<vector<int>> vec1 = {{5,4},{6,4},{6,7},{2,3}};
    cout << s.maxEnvelopes(vec1) << endl;

    return 0;
}
