#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define f(i,j,n) for(int i=j; i<n; i++)
#define fo(i,j) for(auto i: j)
#define vec vector<int>

void dfs(int node, int parent, vector<int> &disc, vector<int> &low, unordered_map<int, bool> vis, unordered_map<int, list<int>> adj, vector<int> &ap, int &timer)
{
    vis[node] = true;
    disc[node] = low[node] = timer++;
    int child = 0;

    fo(nbr, adj[node])
    {
        if(nbr == parent)
            continue;

        if(!vis[nbr])
        {
            dfs(nbr, node, disc, low, vis, adj, ap, timer);
            low[node] = min(low[node], low[nbr]);
            if(low[nbr] >= disc[node] && parent != -1)
            {
                ap[node] = 1;
            }
        }
        else
        {
            low[node] = min(low[node], low[nbr]);
        }
    }

}

int main(){

    int n, e;
    vector<pair<int, int>> edges;
    unordered_map<int, list<int>> adj;

    for(int i = 0; i < n; i++)
    {
        int u = edges[i].first;
        int v = edges[i].second;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int timer = 0;
    vector<int> disc(n);
    vector<int> low(n);
    unordered_map<int, bool> vis;
    vector<int> ap(n, 0);

    for (int i = 0; i < n; i++)
    {
        disc[i] = -1;
        low[i] = -1;
    }

    //dfs
    for (int i = 0; i < n; i++)
    {
        if(!vis[i])
        {
            dfs(i, -1, disc, low, vis, adj, ap, timer);
        }
    }

    return 0;
}