#include <iostream>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, a[6] = {1, 2, 3, 4, 5, 6}, ans;
        cin >> n;
        for (int i = 0; i < 6; i++)
        {
            while (n >= ans)
            {
                a[i] = a[i] + 1;
            }
            ans += a[i];
        }
        bool sum = true;
        for (int i = 0; i < 6; i++)
        {
            if (a[i] == a[i + 1])
            {
                sum = false;
            }
        }
        if (n < 21)
        {
            cout << "no" << endl;
        }
        else if (!sum)
        {
            cout << "no" << endl;
        }
        else if (sum)
        {
            cout << "yes" << endl;
        }
    }
    // your code goes here
    return 0;
}