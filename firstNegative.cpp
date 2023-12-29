#include <iostream>
#include <deque>
#include <vector>
using namespace std;

vector<int> firstNegative(int a[], int n, int k)
{
    deque<int> dq;
    vector<int> ans;
    int negative = -1;

    for (int i = 0; i < k; i++)
    {
        if(a[i] < 0)
        {
            dq.push_back(i);
        }
    }

    if(dq.size() > 0)
    {
        ans.push_back(a[dq.front()]);
    }
    else
    {
        ans.push_back(0);
    }

    for (int i = k; i < n; i++)
    {
        if(!dq.empty() && (i-dq.front() >= k))
        {
            dq.pop_front();
        }

        if(a[i] < 0)
        {
            dq.push_back(i);
        }

        if(dq.size() > 0)
        {
            ans.push_back(a[dq.front()]);
        }
        else
        {
            ans.push_back(0);
        }
    }
    return ans;
}

int main()
{


    return 0;
}