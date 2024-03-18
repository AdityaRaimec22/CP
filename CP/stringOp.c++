#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define f(i,j,n) for(int i=j; i<n; i++)
#define fo(i,j) for(auto i: j)
#define vec vector<int>

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;

    set<char> st;
    f(i,0,n)
    {
        st.insert(s[i]);
    }

    int distinct = st.size();

    if(distinct > n/2 && n%2 == 0)
    {
        cout << 0 << endl;
        return;
    }
    
    if(distinct > n/2 && n%2 != 0)
    {
        cout << 1 << endl;
        return;
    }

    cout << n/distinct << endl;
    return;
}

int main(){

    int t;
    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}