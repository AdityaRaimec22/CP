#include<bits/stdc++.h>
using namespace std;
#define int long long
#define f(i,j,n) for(int i=j; i<n; i++)
#define fo(i,j) for(auto i: j)
#define vec vector<int>

void dfs(vector<int> &component, unordered_map<int, bool> &visited, int node, unordered_map<int, list<int>> &mp) {
    component.push_back(node);
    visited[node] = true;

    for(auto i: mp[node]) {
        if(!visited[i]){
            // visited[i] = true;
            dfs(component, visited, i, mp);
        }
    }
}

vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges) {
    // Write your code here
    unordered_map<int, list<int>> mp;
    unordered_map<int, bool> visited;
    for (int i = 0; i < E; i++) {
        int u = edges[i][0];
        int v = edges[i][1];

        mp[u].push_back(v);
        mp[v].push_back(u);
    }

    vector<vector<int> > ans;

    for(int i = 0; i < V; i++) {
        if(!visited[i]) {
            vector<int> component;
            dfs(component, visited, i, mp);
            ans.push_back(component);
        }
    }
    return ans;
}

signed main(){

    int n = 5, m = 4;
    vector<vec> v = {{0,2}, {0,1}, {1,2}, {3,4}};

    f(i,0,depthFirstSearch(n,m,v).size()) {
        f(j,0,depthFirstSearch(n,m,v)[i].size()) {
            cout << depthFirstSearch(n,m,v)[i][j] << " ";
        }
        cout << endl;
    }


    return 0;
}