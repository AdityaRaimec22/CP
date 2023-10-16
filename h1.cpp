#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,m=0; cout<<endl; int l,sum1=0,sum2=0;
    // const int m = 1e6+2;
    vector<int> v1,v2 ;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        m+=i;
        cin>>m;
        v2.push_back(m);
        // cin>>l;
        // v1.push_back(l);
    }
    for(int i=0;i<n;i++)
    {
        cout<<v2[i]<<" ";
    }
    cout<<endl;
    // for(int i=0;i<n;i++)
    // {
    //     sum2+=v2[i];
    //     // sum1+=v1[i];
    // }
    
    // if(sum1==sum2)
    // {
    //     cout<<"YES"<<endl;
    // }
    // else
    // {
    //     cout<<"NO"<<endl;
    // }
    
// 	your code goes here
	return 0;
}