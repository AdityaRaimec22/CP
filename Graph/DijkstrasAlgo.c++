#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define f(i,j,n) for(int i=j; i<n; i++)
#define fo(i,j) for(auto i: j)
#define vec vector<int>

vec minDist(vector<vec> v, int vertices, int edges, int src)
{
    unordered_map<int, list<pair<int, int> > > adj;
    f(i,0,edges)
    {
        int u = v[i][0];
        int w = v[i][1];
        int z = v[i][2];

        adj[u].push_back(make_pair(w,z));
        adj[w].push_back(make_pair(u,z));
    }
    vec dist(vertices);
    f(i,0,vertices)
    {
        dist[i] = INT_MAX;
    }
    set<pair<int, int> > st;
    dist[src] = 0;
    st.insert(make_pair(0,src));
    while (!st.empty())
    {
        auto top = *(st.begin());

        int topNodeDist = top.first;
        int topNode = top.second;
        st.erase(top);

        fo(i,adj[topNode])
        {
            if(topNodeDist + i.second < dist[i.first])
            {
                auto some = st.find(make_pair(dist[i.first], i.first));

                if(some != st.end())
                {
                    st.erase(some);
                }

                dist[i.first] = topNodeDist + i.second;
                st.insert(make_pair(dist[i.first], i.first));
            }
        }
    }
    return dist;
}

int main() {


    return 0;
}