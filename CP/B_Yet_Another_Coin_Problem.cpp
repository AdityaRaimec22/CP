#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define f(i,j,n) for(int i=j; i<n; i++)
#define fo(i,j) for(auto i: j)
#define vec vector<int>

int solve(int n, vector<int> &v) { // Corrected function signature
    if(n == 0 || v.empty()) { // Corrected condition for v being empty
        return 0;
    }

    int ans = 0;
    f(i,0,n) {
        int include = 0;
        if(n >= v[i])
            include = 1 + solve(n-v[i], v);

        vector<int> v_copy = v; // Create a copy of v
        v_copy.erase(v_copy.begin()); // Erase first element from the copy
        int exclude = 0 + solve(n, v_copy);

        ans = max(include, exclude);
    }
    return ans; // Added return statement
}

int main(){
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        vec v = {1, 3, 6, 10, 15};
        cout << solve(n, v) << endl;
    }

    return 0;
}