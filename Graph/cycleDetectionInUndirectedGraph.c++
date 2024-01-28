#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define f(i,j,n) for(int i=j; i<n; i++)
#define fo(i,j) for(auto i: j)
#define vec vector<int>

bool CDDFS(int node, int parent, unordered_map<int, bool> visited, unordered_map<int, list<int> > mp)
{
    fo(i,mp[node])
    {
        if(!visited[i])
        {
            bool detectCycle = CDDFS(i, node, visited, mp);
            if(detectCycle)
            {
                return true;
            }
            else if(parent != i)
            {
                return true;
            }
        }
    }
    return false;
}

bool CDBFS(int node, unordered_map<int, list<int> > mp, int n, unordered_map<int, bool> visited)
{
    unordered_map<int, int> parent;
    queue<int> q;
    q.push(node);
    parent[node] = -1;
    visited[node] = true;

    while (!q.empty())
    {
        int num = q.front();
        q.pop();

        fo(i, mp[node])
        {
            if(visited[i] == true && i != parent[num])
            {
                return true;
            }
            else
            {
                q.push(i);
                visited[i] = true;
                parent[i] = num;
            }
        }
    }
}

bool cycleDetection(vector<vec> &edges, int n, int m)
{
    unordered_map<int, list<int> > mp;

    f(i,0,edges.size())
    {
        int u = edges[i][0];
        int v = edges[i][1];

        mp[u].push_back(v);
        mp[v].push_back(u);
    }

    unordered_map<int, bool> visited;

    f(i,0,n)
    {
        if(!visited[i])
        {
            if(CDBFS(i, mp, n, visited))
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