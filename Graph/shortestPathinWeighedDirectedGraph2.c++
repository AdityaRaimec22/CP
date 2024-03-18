#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define f(i,j,n) for(int i=j; i<n; i++)
#define fo(i,j) for(auto i: j)
#define vec vector<int>

class Graph {
    public:
    unordered_map<int, list<pair<int, int>> > adj;
    
    void adj(int e, int w, int u)
    {
        pair<int, int> p = make_pair(e, w);
        adj[u].push_back(p);
    }

    void dfs(int node, unordered_map<int, bool> &visited,stack<int> &topo)
    {
        visited[node] = true;

        fo(i, adj[node])
        {
            if(!visited[i.first])
            {
                dfs(i.first, visited, topo);
            }
        }
        topo.push(node);
    }

    vec shortestPath(int src, vec ans, stack<int> topo)
    {
        ans[src] = 0;

        while (!topo.empty())
        {
            int top = topo.top();
            topo.pop();

            if(ans[top] != INT_MAX)
            {
                fo(i, adj[top])
                {
                    if(ans[top] + i.second < ans[i.first])
                    {
                        ans[i.first] = ans[top] + i.second;
                    }
                }
            }
        }
    }
};

int main(){


    return 0;
}