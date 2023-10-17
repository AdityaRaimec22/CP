#include <iostream>
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--)
    {
        int n,a[n],sum=0;
        cin>>n;
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
            sum+=a[i];
        }
        // for(int i=0;i<n;i++)
        // {
        //     sum+=a[i];
        // }
        if(sum%2==0)
        {
            cout<<"yes"<<endl;
        }
        else{
            cout<<"no"<<endl;
        }
    }
	// your code goes here
	return 0;
}