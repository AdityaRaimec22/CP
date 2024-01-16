#include <bits/stdc++.h>
using namespace std;

int main()
{

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        string s1, f1;
        cin >> s1 >> f1;
        int oneCount_s = 0;
        int oneCount_f = 0;
        int d_value = 0;
        int ans = 0;
        int opn = 0;
        for (int i = 0; i < n; i++)
        {
            if (s1[i] == '1')
            {
                oneCount_s++;
            }
            if (f1[i] == '1')
            {
                oneCount_f++;
            }
        }

        for (int i = 0; i < n; i++)
        {
            if (s1[i] != f1[i])
            {
                d_value++;
            }
        }

        if (oneCount_f == oneCount_s)
        {

            ans = d_value / 2;
        }

        if (oneCount_s > oneCount_f)
        {
            opn = oneCount_s - oneCount_f;
            d_value = d_value - opn;
            ans = d_value / 2 + opn;
        }

        if (oneCount_f > oneCount_s)
        {
            opn = oneCount_f - oneCount_s;
            d_value = d_value - opn;
            ans = d_value / 2 + opn;
        }

        cout << ans << endl;
    }

    return 0;
}