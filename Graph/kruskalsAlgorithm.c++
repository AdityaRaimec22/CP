#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define f(i,j,n) for(int i=j; i<n; i++)
#define fo(i,j) for(auto i: j)
#define vec vector<int>

bool cmp(vec &a, vec &b)
{
    return a[2] < b[2];
}

void makeSet(vec &rank, vec &parent, int n)
{
    f(i,0,n)
    {
        rank[i] = 0;
        parent[i] = i;
    }
}

int findParent(vec &parent, int node)
{
    if(parent[node] == node)
    {
        return node;
    }

    return parent[node] = findParent(parent, node);
}

void unionSet(int u, int v, vec &parent, vec &rank)
{
    if(rank[u] < rank[v])
    {
        parent[u] = v;
    } 
    else if (rank[v] < rank[u])
    {
        parent[v] = u;
    }
    else
    {
        parent[v] = u;
        rank[u]++;
    }
}

int minimumSpannigTree(vector<vec> &edges, int n)
{
    sort(edges.begin(), edges.end(), cmp);
    vec rank(n);
    vec parent(n);
    makeSet(rank, parent, n);

    int minWeight = 0;

    f(i,0,edges.size())
    {
        int u = findParent(parent, edges[i][0]);
        int v = findParent(parent, edges[i][1]);
        int wt = edges[i][2];

        if(u != v)
        {
            minWeight += wt;
            unionSet(u, v, parent, rank);
        }
    }
}

int main(){


    return 0;
}