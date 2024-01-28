#include<bits/stdc++.h>
using namespace std;

void dfs(int node, vector<int> component, unordered_map<int, bool> visited, unordered_map<int, list<int>> adj)
{
    component.push_back(node);
    visited[node] = true;

    for(auto i: adj[node])
    {
        if(!visited[i])
        {
            dfs(i, component, visited, adj);
        }
    }
}

vector<vector<int> > depthFirstSearch(int v, int e, vector<vector<int> > nodes)
{
    unordered_map<int, bool> visited;
    vector<vector<int> > ans;
    unordered_map<int, list<int>> adj;

    for(int i = 0; i < nodes.size(); i++)
    {
        int u = nodes[i][0];
        int v = nodes[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for(int i = 0; i < v; i++)
    {
        if(!visited[i])
        {
            vector<int> component;
            dfs(i, component, visited, adj);
            ans.push_back(component);
        }
    }

    return ans;
}

int main(){


    return 0;
}