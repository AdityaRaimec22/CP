#include<bits/stdc++.h>
using namespace std;

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)
{
    unordered_map<int, list<int>> adj;

    for(int i = 0; i < e; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
    }

    //find all indegrees
    vector<int> indegree(v);

    for(auto i: adj)
    {
        for(auto j: i.second)
        {
            indegree[j]++;
        }
    }

    //0 indegree wale ko push kardo.
    queue<int> q;
    
    for(int i = 0; i < v; i++)
    {
        if(indegree[i] == 0)
        {
            q.push(i);
        }
    }

    //do bfs
    vector<int> ans;

    while (!q.empty())
    {
        int front = q.front();
        q.pop();

        ans.push_back(front);

        for(auto neighbour: adj[front])
        {
            indegree[neighbour]--;
            
            if(indegree[neighbour] == 0)
            {
                q.push(neighbour);
            }
        }
    }
}

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    // Write your code here.
    unordered_map<int, list<int> > mp;
    for(int i = 0; i < e; i++) {
        int u = edges[i][0];
        int v = edges[i][1];

        mp[u].push_back(v);
    }

    vector<int> ans;
    unordered_map<int, int> indegree;
    queue<int> q;

    for(auto i: indegree) {
        if(i.second == 0) {
            q.push(i.first);
        }
    }

    while(!q.empty()) {
        int front = q.front();
        q.pop();

        ans.push_back(front);

        for(auto i: mp[front]) {

            indegree[i]--;
            if(indegree[i] == 0) {
                q.push(i);
            }
        }
    }

    return ans;
}

int main() {


    return 0;
}