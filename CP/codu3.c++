#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define f(i,j,n) for(int i=j; i<n; i++)
#define fo(i,j) for(auto i: j)
#define vec vector<int>

int main(){

    int t;
    cin >> t;
    
    while (t--)
    {
        int n, k, m;
        cin >> n >> k >> m;
        string s;
        cin >> s;
        int a = 97;
        bool ans = true;
        bool minAns = true;
        f(i,0,n)
        {
            if(m < n*k)
            {
                minAns = false;
                break;
            }
            if(s[i] == char(a+i))
            {
                continue;
            }
            else
            {
                ans = false;
                break;
            }
        }
    }
    

    return 0;
}