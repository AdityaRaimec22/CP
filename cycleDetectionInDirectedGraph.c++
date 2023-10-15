#include<bits/stdc++.h>
using namespace std;

bool checkCycle(int i, unordered_map<int, bool> &visited, unordered_map<int, bool> &dfsVisited, unordered_map<int, list<int>> &adj){
    visited[i] = true;
    dfsVisited[i] = true;

    for(auto neighbour : adj[i])
    {
        if(!visited[neighbour])
        {
            bool cycleDetected = checkCycle(neighbour, visited, dfsVisited, adj);
            {
                if(cycleDetected)
                {
                    return true;
                }
                else if(dfsVisited[neighbour])
                {
                    return true;
                }
            }
        }
    }
    dfsVisited[i] = false;
    return false;
}   

int detectCylce(int n, vector< pair <int, int> > &edges)
{
    //create adj lsit
    unordered_map<int, list<int>> adj;
    for(int i = 0; i< edges.size(); i++)
    {
        int u = edges[i].first;
        int v = edges[i].second;

        adj[u].push_back(v);
    }

    //call dfs for all component
    unordered_map<int, bool> visited;
    unordered_map<int, bool> dfsVisited;
    for (int i = 1; i <= n; i++)
    {
       if (!visited[i])
       {
            bool cycleFound = checkCycle(i ,visited, dfsVisited, adj);
            if (cycleFound)
            {
                return true;
            }
       }
    }
    return false;
}

void topoSort(int node, unordered_map<int, bool> visited, stack<int> s, unordered_map<int, list<int>> adj)
{
    visited[node] = true;

    for(auto neighbour: adj[node])
    {
        if(!visited[neighbour])
        {
            topoSort(neighbour, visited, s, adj);
        }
    }

    s.push(node);
}

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)
{
    unordered_map<int, list<int>> adj;
    for (int i = 0; i < e; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
    }

    //call dfs topological sort  util function for all components
    unordered_map<int, bool> visited;
    stack<int> s;

    for(int i = 0; i < v; i++)
    {
        if(!visited[i])
        {
            topoSort(i, visited, s, adj);
        }
    }

    vector<int> ans;

    while (!s.empty())
    {
        ans.push_back(s.top());
        s.pop();
    }
    return ans;
}

int main(){


    return 0;
}