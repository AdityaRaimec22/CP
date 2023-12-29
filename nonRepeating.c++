#include<iostream>
#include<queue>
#include<map>
using namespace std;

int main()
{
    queue<int> q;

    q.push(1);
    q.push(2);
    cout << q.front() << endl;

    return 0;
}