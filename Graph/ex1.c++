#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define f(i,j,n) for(int i=j; i<n; i++)
#define fo(i,j) for(auto i: j)
#define vec vector<int>



int main(){
    int n = 1;

    while (n != -1)
    {
        int a, b;
        cin >> a >> b;
        cout << a%b << endl;
        cin >> n;
    }
    

    return 0;
}