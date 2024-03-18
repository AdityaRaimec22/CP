#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define f(i,j,n) for(int i=j; i<n; i++)
#define fo(i,j) for(auto i: j)
#define vec vector<int>

vec primsAlgo(int n, int m, vector<pair<pair<int, int>, int>> g)
{
    unordered_map<int, list<pair<int, int> > > adj;
    f(i,0,g.size())
    {
        int u = g[i].first.first;
        int v = g[i].first.second;
        int w = g[i].second;

        adj[u].push_back(make_pair(v,w));
        adj[v].push_back(make_pair(u,w));
    }

    vec parent(n);
    vector<bool> mst(n);
    vec weight(n);

    f(i,0,n)
    {
        parent[i] = -1;
        weight[i] = INT_MAX;
        mst[i] = false;
    }

    parent[0] = -1;
    weight[0] = 0;

    f(v,0,n)
    {
        int u;
        int mini = INT_MAX;

        if(mst[v] == false && mini < weight[v])
        {
            u = v;
            mini = weight[v];
        }
    }

    
}

int main(){


    return 0;
}