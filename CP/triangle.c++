#include<bits/stdc++.h>
using namespace std;

int combination(int n)
{
    return n*(n-1)*(n-2)/6;
}

int noOfTriangle(vector<int> &v, int n)
{
    if(n < 3)
    {
        return 0;
    }
    unordered_map<int, int> mp;
    int sum = 0;
    int count = 0;
    for(int i = 0; i < n; i++)
    {
        mp[v[i]]++;
    }

    if(mp[v[0]] == 7)
    {
        return combination(n);
    }

    
}

int main(){

    int t;
    cin >> t;

    while (t--)
    {
        vector<int> v;
        int n;
        int ans = 0;
        cin >> n;

        for(int i = 0; i < n; i++)
        {
            int a;
            cin >> a;
            v.push_back(pow(2, a));
        }

        sort(v.begin(), v.end());

        ans = noOfTriangle(v, n);

        cout << ans << endl;

    }
    

    return 0;
}