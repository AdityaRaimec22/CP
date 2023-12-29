#include<iostream>
#include<vector>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, m;
        cin >> n >> m;

        if(n >= m)
        {
            cout << n << endl;
        }
        else
        {
            cout << m << endl;
        }
    }
    return 0;
}