#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    cin >> n;
    vector<int> v, w;
    for(int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        v.push_back(a);
    }
    cin >> m;
    for(int i = 0; i < m; i++)
    {
        int b;
        cin >> b;
        w.push_back(b);
    }
    int maxRatio = 0;
    int count = 1;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            int ratio = 0;
            if(w[j]%v[i] == 0)
            {
                ratio = w[j]/v[i];
                if(ratio == maxRatio)
                {
                    count++;
                }
                else if(ratio > maxRatio)
                {
                    count = 1;
                    maxRatio = ratio;
                }
            }
        }
    }
    cout << count << endl;
    return 0;
}