#include<bits/stdc++.h>
using namespace std;
#define int long long
#define f(i,j,n) for(int i=j; i<n; i++)
#define fo(i,j) for(auto i: j)
#define vec vector<int>

void bfs(int node,  vector<int> &ans, unordered_map<int, bool> &visited, unordered_map<int, list<int>> &mp) {
    queue<int> q;
    q.push(node);
    visited[node] = true;
    ans.push_back(node);

    while(!q.empty()) {
        int top = q.front();
        q.pop();

        for(auto i: mp[top]) {
            if(!visited[i]) {
                q.push(i);
                ans.push_back(i);
                visited[i] = true;
            }
        }
    }
}

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    // Write your code here
    unordered_map<int, list<int>> mp;
    for(int i = 0; i < e; i++) {
        int u = edges[i][0];
        int v = edges[i][1];

        mp[u].push_back(v);
    }

    vector<int> ans;
    unordered_map<int, bool> visited;
    for(auto i: edges) {
        if(!visited[i[0]]) {
            bfs(i[0], ans, visited, mp);
        }
    }
    return ans;
}

signed main(){

    int v = 1, e = 0;
    vector<vector<int>> edges(v, vec(2, 0));
    // edges = {{}};

    vector<int> ans = topologicalSort(edges, v ,e);

    f(i,0,ans.size()) {
        cout << ans[i] << " ";
    } cout << endl;

    return 0;
}