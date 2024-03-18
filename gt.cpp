#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define f(i,j,n) for(int i=j; i<n; i++)
#define fo(i,j) for(auto i: j)
#define vec vector<int>

vector<vector<int>>printAdjacency(int n, int m, vector<vector<int>>&edges)
{
    vector<vec> ans(n);

    for (int i = 0; i < m; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        ans[u].push_back(v);
        ans[v].push_back(u);
    }

    vector<vector<int>> adj(n);
    for (int i = 0; i < n; i++)
    {
        adj[i].push_back(i);

        for (int j = 0; j < ans[i].size(); j++)
        {
            adj[i].push_back(ans[i][j]);
        }
    }
    return ans;
}

int main(){

    int n = 4, m = 3;
    vector<vec> v = {{1,2}, {0,3}, {2,3}};

    f(i,0,printAdjacency(n,m,v).size()) {
        f(j,0,printAdjacency(n,m,v)[i].size()) {
            cout << printAdjacency(n,m,v)[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}