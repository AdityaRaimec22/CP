#include<bits/stdc++.h>
using namespace std;

int main(){

    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;

        int a[n], b[n];

        for(int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        int sum = 0;
        for(int i = 0; i < n; i++)
        {
            sum += a[i];
        }

        if(k < 2 && a[0] > a[1])
        {
            cout << "NO" << endl;
        }
        else
        {
            cout << "YES" << endl;
        }
    }

    return 0;
}