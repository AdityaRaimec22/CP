#include <iostream>
#include <queue>
#include <stack>
using namespace std;

queue<int> modifyQueue(queue<int> q, int k)
{
    stack<int> s;

    for (int i = 0; i < k; i++)
    {
        int val = q.front();
        q.pop();
        s.push(val);
    }

    while (!s.empty())
    {
        int val = s.top();
        s.pop();
        q.push(val);
    }
    
    int l = q.size() - k;

    while (l--)
    {
        int val = q.front();
        q.pop();
        q.push(val);
    }

    return q;
    
}

int main()
{
    queue<int> q, v;

    for (int i = 0; i < 5; i++)
    {
        q.push(i+1);
    }

    v = modifyQueue(q,3);

    while (!v.empty())
    {
        int val = v.front();
        v.pop();
        cout << val << " ";
    }cout << endl;
    
    
}