#include <iostream>
#include <stack>
#include <climits>
using namespace std;

class specialStack
{
    stack<int> s;
    int mini = INT_MAX;

    void push(int data)
    {
        if(s.empty())
        {
            s.push(data);
            mini = data;
        }
        else
        {
            if(data < mini)
            {
                s.push(2*data - mini);
                mini = data;
            }
            else
            {
                s.push(data);
            }
        }
    }

    int pop()
    {
        if(s.empty())
            return -1;

        
    }
};