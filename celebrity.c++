#include<iostream>
#include<vector>
#include<stack>
using namespace std;

bool knows(vector<vector<int>> v, int a, int b, int n)
{
    if(v[a][b] == 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int celebrity(vector<vector<int> > v, int n)
{
    stack<int> s;

    for(int i = 0; i < n; i++)
    {
        s.push(i);
    }

    while (s.size() > 1)
    {
        int a = s.top();
        s.pop();

        int b = s.top();
        s.pop();

        if(knows(v, a, b, n))
        {
            s.push(b);
        }
        else
        {
            s.push(a);
        } 
    }
    int ans = s.top();

    int zeroCount = 0;

    for(int i = 0; i < n; i++)
    {
        if(v[ans][i] == 0)
        {
            zeroCount++;
        }
    }

    if(zeroCount != n)
        return -1;

    int oneCount = 0;

    for(int i = 0; i < n; i++)
    {
        if(v[i][ans] == 1)
        {
            oneCount++;
        }
    }

    if(oneCount != n)
        return -1;

    return ans;
}

int main()
{

    return 0;
}