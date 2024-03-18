#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define f(i,j,n) for(int i=j; i<n; i++)
#define fo(i,j) for(auto i: j)
#define vec vector<int>

vec bfs(int n, unordered_map<int, list<int>>& mp) {
    
}

vector<int> bfsTraversal(int n, vector<vector<int>> &adj){

    unordered_map<int, list<int>> mp;
    for(int i = 0; i < adj.size(); i++) {
        int u = adj[i][0];
        int v = adj[i][1];

        mp[u].push_back(v);
    }

    return bfs(n, mp);
}

int main(){


    return 0;
}