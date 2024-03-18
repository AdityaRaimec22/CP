#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define f(i, j, n) for (int i = j; i < n; i++)
#define fo(i, j) for (auto i : j)
#define vec vector<int>

class Solution
{
private:
    static bool Compare(const vector<int> &a, const vector<int> &b)
    {
        return a[0] < b[0];
    }

    bool check(vec curr, vec prev)
    {
        if (prev[0] <= curr[0] && prev[1] <= curr[1] && prev[2] <= curr[2])
        {
            return true;
        }
        return false;
    }

    // int solve(int &n, vector<vector<int>> &cuboids, int curr, int &prev, vector<vec>& dp)
    // {
    //     if (curr == n)
    //     {
    //         return 0;
    //     }

    //     if(dp[curr][prev+1] != -1) {
    //         return dp[curr][prev+1];
    //     }

    //     int take = 0;
    //     if (prev == -1 || check(curr, prev, cuboids))
    //     {
    //         take = cuboids[curr][2] + solve(n, cuboids, curr + 1, curr, dp);
    //     }

    //     int notTake = 0 + solve(n, cuboids, curr + 1, prev, dp);

    //     return dp[curr][prev+1] = max(take, notTake);
    // }

    int solveTab(vector<vector<int>> &cuboids) {

        int n = cuboids.size();
        // vector<vec> dp(n, vec(n+1, 0));

        vec currRow(n+1, 0);
        vec nextRow(n+1, 0);

        for(int curr = n-1; curr >= 0; curr--) {
            for(int prev = curr-1; prev >= -1; prev--) {
                int take = 0;
                if (prev == -1 || check(cuboids[curr], cuboids[prev]))
                {
                    take = cuboids[curr][2] + nextRow[curr+1];
                }

                int notTake = 0 + nextRow[prev+1];

                currRow[prev+1] = max(take, notTake);
            }
            nextRow = currRow;
        }

        return nextRow[0];
    }

public:
    int maxHeight(vector<vector<int>> &cuboids)
    {
        for (auto &cuboid : cuboids)
        {
            sort(cuboid.begin(), cuboid.end());
        }

        sort(cuboids.begin(), cuboids.end());

        fo(i, cuboids) {
            fo(j, i) {
                cout << j << " ";
            }
            cout << endl;
        }

        cout << endl << "new line" << endl;

        sort(cuboids.begin(), cuboids.end(), Comapare);

        fo(i, cuboids) {
            fo(j, i) {
                cout << j << " ";
            }
            cout << endl;
        }

        int curr = 0;
        int prev = -1;
        int n = cuboids.size();

        vector<vec> dp(n+1, vec(n+1, -1));

        return solveTab(cuboids);
    }
};

int main()
{

    Solution s;
    vector<vector<int>> vec1 = {
        {92, 47, 83},
        {75, 20, 87},
        {68, 12, 83},
        {12, 85, 15},
        {16, 24, 47},
        {69, 65, 35},
        {96, 56, 93},
        {89, 93, 11},
        {86, 20, 41},
        {69, 77, 12},
        {83, 80, 97},
        {90, 22, 36}};

    int ans = s.maxHeight(vec1);

    cout << ans << endl;

    return 0;
}