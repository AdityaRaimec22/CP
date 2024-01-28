#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define f(i,j,n) for(int i=j; i<n; i++)
#define fo(i,j) for(auto i: j)
#define vec vector<int>

bool checkCycle(int node, unordered_map<int, list<int>> adj, unordered_map<int, bool> visited, unordered_map<int, bool> dfsVisited)
{
    visited[node] = true;
    dfsVisited[node] = true;

    fo(i,adj[node])
    {
        if(!visited[i])
        {
            if(checkCycle(i, adj, visited, dfsVisited))
            {
                return true;
            }
            else if(dfsVisited[i])
            {
                return true;
            }
        }
    }

    dfsVisited[node] = false;
    return false;
}

bool cycleInDirectedGraph(vector<vec> edges, int n, int m)
{
    unordered_map<int, list<int>> adj;

    f(i,0,edges.size())
    {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
    }

    unordered_map<int, bool> visited;
    unordered_map<int, bool> dfsVisited;

    f(i,0,n)
    {
        if(!visited[i])
        {
            if(checkCycle(i, adj, visited, dfsVisited))
            {
                return true;
            }
        }
    }

    return false;
}

int main(){


    return 0;
}