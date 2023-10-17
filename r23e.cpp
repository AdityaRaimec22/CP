#include <iostream>
using namespace std;

int main() {
    // int t;
    // cin>>t;
    // while(t--)
    // {
        int n,a[n],b[n],sum1=0,sum2=0;
        cin>>n;
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
            sum1+=a[i];
        }
        cout<<endl;
        for(int i=0;i<n;i++)
        {
            cin>>b[i];
            sum2+=b[i];
        }
        cout<<sum1<<" "<<sum2<<endl;
        
        
    // }
	// your code goes here
	return 0;
}