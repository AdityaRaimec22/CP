#include <iostream>
#include <stack>
using namespace std;

void insertSorted(stack<int> &s, int num)
{
    if((s.empty()) || (!s.empty() && s.top() < num))
    {
        s.push(num);
        return;
    }

    int n = s.top();
    s.pop();

    insertSorted(s, num);

    s.push(n);
}

void sortStack(stack<int> &s)
{
    if(s.empty())
        return;

    int num = s.top();
    s.pop();

    sortStack(s);

    insertSorted(s,num);
}

int main()
{
    stack<int> s;
    s.push(9);
    s.push(1);
    s.push(5);
    s.push(6);

    sortStack(s);

    for (int i = 0; i < 4; i++)
    {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
    

    return 0;
}