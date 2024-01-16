#include<bits/stdc++.h>
using namespace std;

int main(){
    
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<pair<int, int>> v;
        int v2 = 0;
        while (n--)
        {
            int a, b;
            cin >> a >> b;
            pair<int, int> p = make_pair(a, b);
            v.push_back(p);
        }

        int max1 = INT_MIN;
        int min2 = INT_MAX;

        for(auto i: v)
        {
            if(i.first == 1)
            {
                if(i.second > max1)
                {
                    max1 = i.second;
                }
            }
            else if(i.first == 2)
            {
                if(i.second < min2)
                {
                    min2 = i.second;
                }
            }
        }

        for(auto i: v)
        {
            if(i.first == 3 && i.second <= min2 && i.second >= max1)
            {
                v2++;
            }
        }

        if(min2 - max1 - v2 >= 0)
        {
            cout << min2 - max1 - v2 + 1 << endl;
        }
        else
        {
            cout << 0 << endl;
        }
    }

    return 0;
}