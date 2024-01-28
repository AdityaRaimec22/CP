#include<bits/stdc++.h>
using namespace std;



int main(){

    long long s, n;
    cin >> s >> n;
    long long health = s;
    long long ans = true;

    for(long long i = 0; i < n; i++)
    {
        long long x, y;
        cin >> x >> y;

        if(health > x)
        {
            health += s+y;
            // ans = true;
        }
        else
        {
            ans = false;
            // break;
        }
    }

    if(ans)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }

    return 0;
}