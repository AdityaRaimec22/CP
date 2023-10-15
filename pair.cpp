#include<iostream>
#include<map>
#include<vector>
using namespace std;

int main(){

    vector<int> v;

    

    map<int, int> m1;

    m1[1] = 1;
    m1[2] = 2;

    // int m2 = m1.insert();

    pair<int, int> p;
    p = make_pair(0 ,0);

    cout << m1[1] << endl;

    cout << p.first << endl;
    
    return 0;
}