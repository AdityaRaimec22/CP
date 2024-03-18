#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define f(i,j,n) for(int i=j; i<n; i++)
#define fo(i,j) for(auto i: j)
#define vec vector<int>

class Solution {
private:
    int solve(vector<int>& arr, int start, int end, map<pair<int, int>, int>& maxi) {
        if(start >= end) {
            return 0;
        }

        int ans = 1e9+2;
        for(int i = start; i < end; i++) {
            ans = min(ans, maxi[{start, i}]*maxi[{i+1, end}] + solve(arr, start, i, maxi) + solve(arr, i+1, end, maxi));
        }

        return ans;
    }

    int solveMem(vector<int>& arr, int start, int end, map<pair<int, int>, int>& maxi, vector<vector<int> > &dp) {
        if(start >= end) {
            return 0;
        }

        if(dp[start][end] != -1) {
            return dp[start][end];
        }

        int ans = 1e9+2;
        for(int i = start; i < end; i++) {
            ans = min(ans, maxi[{start, i}]*maxi[{i+1, end}] + solveMem(arr, start, i, maxi, dp) + solveMem(arr, i+1, end, maxi, dp));
        }

        return dp[start][end] = ans;
    }

public:
    int mctFromLeafValues(vector<int>& arr) {
        map<pair<int, int>, int> maxi;

        for(int i = 0; i < arr.size(); i++) {
            maxi[{i, i}] = arr[i];
            for(int j = i+1; j < arr.size(); j++) {
                maxi[{i, j}] = max(arr[j], maxi[{i, j-1}]);
            }
        }

        vector<vector<int> > dp(arr.size()+1, vector<int> (arr.size()+1, -1) );

        return solveMem(arr, 0, arr.size()-1, maxi, dp);
    }
};

int main(){


    return 0;
}