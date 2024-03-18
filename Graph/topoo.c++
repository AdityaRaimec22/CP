#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define f(i,j,n) for(int i=j; i<n; i++)
#define fo(i,j) for(auto i: j)
#define vec vector<int>

void topoSort(int node, unordered_map<int, bool> visited, stack<int> s, unordered_map<int, list<int> > adj)
{
    visited[node] = true;

    fo(i,adj[node])
    {
        if(!visited[i])
        {
            topoSort(i, visited, s, adj);
        }
    }

    s.push(node);
}

vec topoo(vector<vec> edges, int v, int e )
{
    unordered_map<int, list<int> > adj;
    f(i,0,e)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
    }

    unordered_map<int, bool> visited;
    stack<int> s;

    f(i,0,v)
    {
        if(!visited[i])
        {
            topoSort(i, visited, s, adj);
        }
    }

    vec ans;

    f(i,0,s.size())
    {
        int top = s.top();
        ans.push_back(top);
    }

    return ans;
}

int main(){


    return 0;
}