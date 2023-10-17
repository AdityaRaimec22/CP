#include<bits/stdc++.h>
// #include<list>
using namespace std;

void Display(list<int> &list1)
{
    list<int> :: iterator it;
    for(it=list1.begin();it!=list1.end();it++)
    {
        cout<<*it<<" ";
    }
    cout<<endl;

}
int main(){
    int n,a[n];
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    list<int> lst;
    // lst.push_back(3);
    for(int i=0;i<n;i++)
    {
        lst.push_back(a[i]);
    }
    lst.reverse();
    Display(lst);
    // for(int i=0;i<n;i++){
    //     cout<<lst(i);
    // }
    return 0;
}
