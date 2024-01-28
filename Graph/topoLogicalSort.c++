#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define f(i,j,n) for(int i=j; i<n; i++)
#define fo(i,j) for(auto i: j)
#define vec vector<int>

vec topoLogicalSort(vector<vec> &edges, int v, int e)
{
    unordered_map<int, list<int> > adj;
    f(i,0,edges.size())
    {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
    }

    unordered_map<int, bool> visited;
}

int main(){


    return 0;
}