#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define f(i,j,n) for(int i=j; i<n; i++)
#define fo(i,j) for(auto i: j)
#define vec vector<int>

void dfs(int node, int parent, int timer, unordered_map<int, list<int> > &adj, vec low, vec disc, unordered_map<int, bool> visited, vector<vec> ans2)
{
    visited[node] = true;
    low[node] = disc[node] = timer++;

    fo(i,adj[node])
    {
        if(node == i)
        {
            continue;
        }
        if(!visited[i])
        {
            dfs(i,node,timer,adj,low,disc,visited, ans2);
            low[node] = min(low[i], low[node]);
            if(low[i] > disc[node])
            {
                vec ans;
                ans.push_back(i);
                ans.push_back(node);
                ans2.push_back(ans);
            }
        }
        else
        {
            low[node] = min(low[i], low[node]);
        }
    }
}

vector<vec> findBridge(vector<vec> &edges, int v, int e)
{
    unordered_map<int, list<int> > adj;
    f(i,0,edges.size())
    {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    unordered_map<int, bool> visited;
    int parent = -1;
    int timer = 0;
    vec low(v);
    vec disc(v);

    f(i,0,v)
    {
        low[i] = -1;
        disc[i] = -1;
    }

    vector<vec> output;
    f(i,0,v)
    {
        if(!visited[i])
        {
            dfs(i,parent, timer, adj, low, disc, visited, output);
        }
    }
}

int main(){


    return 0;
}