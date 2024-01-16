#include<bits/stdc++.h>
using namespace std;

int main(){

    int t;
    cin >> t;
    
    while (t--)
    {
        int a1, b1, a2, b2;
        int a, b;
        cin >> a1 >> b1;
        for(int i = 0; i < 3; i++)
        {
            
            cin >> a >> b;
            if(a1 == a || b1 == b)
            {
                a2 = a;
                b2 = b;
            }
        }
        cout << (a1-a2)*(a1-a2) + (b1-b2)*(b1-b2) << endl;
    }
    
    return 0;
}