#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define f(i,j,n) for(int i=j; i<n; i++)
#define fo(i,j) for(auto i: j)
#define vec vector<int>



int main(){

    int t;
    cin >> t;

    while (t--)
    {
        int x, n;
        cin >> x >> n;
        if(x%n == 0)
        {
            cout << x/n << endl;
        }
        else if(x%n != 0 && x/(x/n) > x/n && x%(x/n) == 0)
        {
            cout << x/n << endl;
        }
        else
        {
            int num = x/n;
            int remainder = x%n;
            while (remainder%num != 0)
            {
                num = num-1;
                remainder = remainder+n;
            }
            cout << num << endl;
        }
    }
    

    return 0;
}