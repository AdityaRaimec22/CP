#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define f(i,j,n) for(int i=j; i<n; i++)
#define fo(i,j) for(auto i: j)
#define vec vector<int>

vec shortestPath(vector<pair<int, int> > &edges, int n, int m, int s, int t)
{
    unordered_map<int, list<int> > adj;

    f(i,0,m)
    {
        int u = edges[i].first;
        int v = edges[i].second;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    unordered_map<int, bool> visited;
    unordered_map<int, bool> parent;
    queue<int> q;
    q.push(s);
    parent[s] = -1;

    while (!q.empty())
    {
        int front = q.front();
        q.pop();

        fo(i,adj[front])
        {
            if(!visited[i])
            {
                visited[i] = true;
                parent[i] = front;
                q.push(i);
            }
        }
    }

    vec ans;
    int currentNode = t;
    ans.push_back(t);

    while (currentNode != s)
    {
        currentNode = parent[currentNode];
        ans.push_back(currentNode);
    }

    reverse(ans.begin(), ans.end());
    return ans;
}

int main() {


    return 0;
}