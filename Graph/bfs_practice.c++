#include<bits/stdc++.h>
using namespace std;

void adjList(vector<pair<int, int> > edges, unordered_map<int, list<int, int> > adj)
{
    for(int i = 0; i < adj.size(); i++)
    {
        int u = edges[i].first;
        int v = edges[i].second;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}

vector<int> bfs(unordered_map<int, bool> visited, unordered_map<int, list<int, int> > adj, vector<int> ans, int node)
{
    queue<int> q;
    q.push(node);
    visited[node] = 1;

    while (!q.empty())
    {
        int frontNode = q.front();
        q.pop();

        ans.push_back(frontNode);

        for(auto i: adj[frontNode])
        {
            if(!visited[i])
            {
                q.push(i);
                visited[i] == 1;
            }
        }
    }
    
}

vector<int> BFS(int vertex, vector<pair<int, int> > edges)
{
    unordered_map<int, list<int, int> > adj;
    vector<int> ans;
    unordered_map<int, bool> visited;

    adjList(edges, adj);

    for(int i = 0; i < vertex; i++)
    {
        if(!visited[i])
        {
            bfs(visited, adj, ans, i);
        }
    }
}

int main(){


    return 0;
}