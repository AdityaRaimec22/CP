#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define f(i,j,n) for(int i=j; i<n; i++)
#define fo(i,j) for(auto i: j)
#define vec vector<int>

vec kahn(vector<vec> &edges, int v, int e)
{
    unordered_map<int, list<int>> adj;
    f(i,0,e)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
    }

    vec ans;
    vec indegree(v);

    fo(i,adj)
    {
        fo(j,i.second)
        {
            indegree[j]++;
        }
    }

    queue<int> q;

    f(i,0,v)
    {
        if(indegree[i] == 0)
        {
            q.push(i);
        }
    }

    while (!q.empty())
    {
        int top = q.front();
        q.pop();

        ans.push_back(top);

        fo(i,adj[top])
        {
            indegree[i]--;

            if(indegree[i] == 0)
            {
                q.push(i);
            }
        }
    }

    return ans;
}

int main(){


    return 0;
}