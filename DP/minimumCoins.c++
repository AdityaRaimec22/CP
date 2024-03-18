#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define f(i,j,n) for(int i=j; i<n; i++)
#define fo(i,j) for(auto i: j)
#define vec vector<int>

class Solution {
    private:
    int solve(vector<int>& cost, int n) {

        int prev1 = cost[0];
        int prev2 = cost[1];

        f(i,2,n)
        {
            int curr = min(prev1, prev2) + cost[i];
            prev2 = prev1;
            prev1 = curr;
        }

        return min(prev1, prev2);
    }
    public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        return solve(cost,n);
    }
};

int main(){

    Solution s;
    vec cost;

    f(i,0,3)
    {
        int a;
        cin >> a;
        cost.push_back(a);
    }

    cout << s.minCostClimbingStairs(cost) << endl;

    return 0;
}