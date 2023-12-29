#include <iostream>
#include <climits>
#include <stack>
using namespace std;

class SpecialStack{
    int mini = INT_MAX;
    stack<int> s;

    public:
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

    void pop()
    {
        if(s.empty())
        {
            return;
        }
        else
        {
            int curr = s.top();
            if(curr > mini)
            {
                s.pop();
            }
            else
            {
                mini = 2*mini - curr;
                s.pop();
            }
        }
    }
};

int main()
{

    return 0;
}