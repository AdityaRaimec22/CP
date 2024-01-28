#include<bits/stdc++.h>
using namespace std;

void prepareAdjList(unordered_map<int, list<int, int>> &adjList, vector<pair<int, int>> &edges)
{
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i].first;
        int v = edges[i].second;

        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
}

void bfs(unordered_map<int, list<int, int>>& adjList, unordered_map<int, bool>& visited, vector<int> &ans, int node){
    queue<int> q;
    q.push(node);
    visited[node] == 1;

    while (!q.empty())
    {
        int frontNode = q.front();
        q.pop();

        //store frontNode into ans
        ans.push_back(frontNode);

        //traverse all neghbours of the fronteNode
        for(auto i:adjList[frontNode])
        {
            if (!visited[i])
            {
                q.push(i);
                visited[i] = 1;
            }
        }
    }
}

vector<int> BFS(int vertex, vector<pair<int, int>> edges)
{
    unordered_map<int, list<int, int>> adjList;
    vector<int> ans;
    unordered_map<int, bool> visited;

    prepareAdjList(adjList, edges);

    // Transverse all components  of a graph
    for (int i = 0; i < vertex; i++)
    {
        if (!visited[i])
        {
            bfs(adjList, visited, ans, i);
        }
    }

    return ans;
}

void dfs(int node, unordered_map<int, bool> &visited, unordered_map<int, list<int>> & adj, vector<int> &component)
{
    component.push_back(node);
    visited[node] = true;

    //hr connected node k liye recursive call
    for(auto i: adj[node])
    {
        if(!visited[i])
        {
            dfs(i, visited, adj, component);
        }
    }
}

vector<vector<int>> depthFirstSearch(int v, int e, vector<vector<int>> &edges)
{
    //prepare adjList
    unordered_map<int, list<int>> adj;
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    vector<vector<int>> ans;
    unordered_map<int, bool> visited;

    for (int i = 0; i < v; i++)
    {
        if (!visited[i])
        {
            vector<int> component;
            dfs(i, visited, adj, component);
            ans.push_back(component);
        }
        
    }
}

int main(){


    return 0;
}