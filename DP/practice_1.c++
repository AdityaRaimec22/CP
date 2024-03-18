#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define f(i,j,n) for(int i=j; i<n; i++)
#define fo(i,j) for(auto i: j)
#define vec vector<int>

int Solve(vec &satisfaction, int index, int time)
{   
    int n = satisfaction.size();
    vector<vec> dp(satisfaction.size()+1, vec(satisfaction.size()+1, 0));

    for(index = n-1; index >= 0; index--) 
    {
        for(time = index; time >= 0; time--) {
            
        }
    }
}

int main(){


    return 0;
}