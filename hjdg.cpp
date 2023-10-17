#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        int count=0,maxs=INT_MIN;
        for(int i=0;i<s.length()-2;i++)
        {
            stoi(s);
            if(s[i]+s[i+1]==1)
            {
                count++;
                break;
            }
            else if(s[i]+s[i+1]!=1)
            {
                count=0;
                break;
            }
            maxs=max(maxs,count);
        }
        if(maxs>0)
        {
            cout<<"GOOD"<<endl;
        }
        else if(maxs==0);
        {
            cout<<"BAD"<<endl;
        }
        
    }
	// your code goes here
	return 0;
}