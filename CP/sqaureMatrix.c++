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

    vector<vector<char> > square(n, vector<char>(n,0));

    f(i,0,n)
    {
        f(j,0,n)
        {
            cin >> square[i][j];
        }
    }

    map<int, int> mp;
    int totalChances = 0;

    f(i,0,n/2)
    {
        f(j,i,n-i-1)
        {
            mp[square[i][j]]++;
            mp[square[j][n-i-1]]++;
            mp[square[n-i-1][n-j-1]]++;
            mp[square[n-j-1][i]]++;

            if(mp.size() == 1)
            {
                mp.clear();
                continue;
            }

            int lastElement = mp.rbegin()->first;

            fo(i,mp) {
                totalChances += ((lastElement - i.first) * i.second);
            }

            mp.clear();
        }
    }

    cout << totalChances << endl;
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