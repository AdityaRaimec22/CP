#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    bool isZero = false;
    int sum = 0;
    int greaterNum = 0;
    int zeroCount = 0;
    
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        sum += num;
        if (sum % 9 == 0)
        {
            greaterNum = sum;
        }
        if (num == 0)
        {
            zeroCount++;
            isZero = true;
        }
    }

    if (greaterNum == 0 && isZero == true)
    {
        cout << 0 << endl;
    }
    else if (zeroCount)
    {
        for (int i = 0; i < greaterNum / 5; i++)
        {
            cout << 5;
        }
        for (int i = 0; i < zeroCount; i++)
        {
            cout << 0;
        }
        cout << endl;
    }
    else
    {
        cout << -1 << endl;
    }
    return 0;
}