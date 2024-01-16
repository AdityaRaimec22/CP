#include<bits/stdc++.h>
using namespace std;

class Graph
{
    public:
    unordered_map<int, list<int> > adj;
    void addEdge(int u, int v, bool direction)
    {
        adj[u].push_back(v);
        if(direction == 0)
        {
            adj[v].push_back(u);
        }
    }

    void printList()
    {
        for(auto i:adj)
        {
            cout<< i.first << "->";
            for (auto j: i.second)
            {
                cout << j << ", ";
            }
            cout << endl;
        }
    }
};

vector<vector<int>>printAdjacency(int n, int m, vector<vector<int>>&edges)
{
    vector<int> ans[n];

    for (int i = 0; i < m; i++)
    {
        int u = edges[i][0];
        int v = edges[i][v];

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
    return adj;
}

int main()
{
    
}