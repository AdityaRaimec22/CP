#include<bits/stdc++.h>
using namespace std;

bool output(int n, string a, string b, string c)
{
    for (int i = 0; i < n; i++)
    {
        /* code */
        if((a[i] == b[i]) && (a[i] != c[i]))
        {
            return true;
        }
        if((a[i] != b[i]) && (a[i] != c[i]) && (b[i] != c[i]))
        {
            return true;
        }
    }
    return false;
}

int main(){

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        bool ans;
        cin >> n;

        string a, b, c;
        cin >> a >> b >> c;

        ans = output(n, a, b, c);

        if(ans)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" <<  endl;
        }
    }

    return 0;
}