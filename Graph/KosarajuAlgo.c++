#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define f(i,j,n) for(int i=j; i<n; i++)
#define fo(i,j) for(auto i: j)
#define vec vector<int>

void dfs(int node, unordered_map<int, bool> visited, unordered_map<int, list<int> > adj, stack<int> st)
{
    visited[node] = true;
    fo(i,adj[node])
    {
        if(!visited[i])
        {
            dfs(i,visited,adj,st);
        }
    }
    st.push(node);
}

void revDfs(int node, unordered_map<int, bool> visited, unordered_map<int, list<int> > adj)
{
    visited[node] = true;
    fo(i,adj[node])
    {
        if(!visited[i])
        {
            revDfs(i,visited,adj);
        }
    }
}

int stronglyConnectedComponents(int v, vector<vec> &edges)
{
    unordered_map<int, list<int> > adj;
    f(i,0,edges.size())
    {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
    }

    stack<int> st;
    unordered_map<int, bool> visited;
    f(i,0,v)
    {
        if(!visited[i])
        {
            dfs(i,visited,adj,st);
        }
    }

    unordered_map<int, list<int> > transpose;
    f(i,0,v)
    {
        visited[i] = 0;
        fo(nbr,adj[i])
        {
            transpose[nbr].push_back(i);
        }
    }

    int count;
    while (!st.empty())
    {
        int top = st.top();
        st.pop();
        if(!visited[top])
        {
            count++;
            revDfs(top,visited,adj);
        }
    }
    
}

int main(){


    return 0;
}