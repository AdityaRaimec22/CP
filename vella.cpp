#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--)
    {
        vector<char> v;
        int n,x,z=(n-x-1)/2,a=(n-x)/2;
        string s1,s2;
        cin>>n>>x;
        if((n-x)%2!=0)
        {
            for(int i=0;i<z;i++)
            {
                // cout<<"+";
                v.push_back('+');
            }
            for(int i=z;i<2*z+1;i++)
            {
                // cout<<"-";
                v.push_back('-');
            }
            for(int i=2*z+1;i<2*z+1+x;i++)
            {
                // cout<<"+";
                v.push_back('+');
            }
        }
        else if((n-x)%2==0)
        {
            for(int i=0;i<a-1;i++)
            {
                // cout<<"+";
                v.push_back('+');
            }
            for(int i=a-1;i<2*a-1;i++)
            {
                // cout<<"-";
                v.push_back('-');
            }
            for(int i=2*a-1;i<2*a-1+x;i++)
            {
                // cout<<"+";
                v.push_back('+');
            }
            for(int i=2*a-1+x;i<2*a+x;i++)
            {
                // cout<<"*";
                v.push_back('*');
            }
        }
        else
        {
            cout<<"-1";
        }
        for(int i=0;i<n;i++)
        {
            cout<<v[i];
        }
        cout<<endl;
    }
	// your code goes here
	return 0;
}