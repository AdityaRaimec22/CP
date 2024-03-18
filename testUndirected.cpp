#include<bits/stdc++.h>
using namespace std;
#define int long long
#define f(i,j,n) for(int i=j; i<n; i++)
#define fo(i,j) for(auto i: j)
#define vec vector<int>

vector<int> shortestPath( vector<pair<int,int>> edges , int n , int m, int s , int t){
	// Write your code here.
	unordered_map<int, list<int> > adj;

	for(int i = 0; i < m; i++) {
		int u = edges[i].first;
		int v = edges[i].second;

		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	unordered_map<int, int> parent;
	unordered_map<int, int> visited;
	queue<int> q;
	vector<int> ans;
	parent[s] = -1;
	q.push(s);

	while(!q.empty()) {
		int front = q.front();
		q.pop();

		visited[front] = true;

		for(auto i: adj[front]) {
			if(!visited[i]) {
				q.push(i);
				parent[i] = front;
			}
		}
	}

	while(parent[t] != s) {
		ans.push_back(t);
		t = parent[t];
	}

	ans.push_back(s);

	reverse(ans.begin(), ans.end());

	return ans;
}


signed main(){


    return 0;
}