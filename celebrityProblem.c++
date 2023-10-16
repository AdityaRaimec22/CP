#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution
{
    private:
    bool knows(vector<vector<int> >& M, int a, int b) {
        if(M[a][b] == 1)
            return true;
        else
            return false;
    }
    public:
    int celebrity(vector<vector<int>> M, int n)
    {
        stack<int> s;
        for (int i = 0; i < n; i++)
        {
            s.push(i);
        }
        while (s.size() > 1)
        {
            int a = s.top();
            s.pop();

            int b = s.top();
            s.pop();

            if(knows(M, a, b))
            {
                s.push(b);
            }
            else
            {
                s.push(a);
            }
        }
         int ans = s.top();
        //step3: single element in stack is potential celeb
        //so verify it
        
        int zeroCount = 0;
        
        for(int i=0; i<n; i++) {
            if(M[ans][i] == 0)
                zeroCount++;
        }
        
        //all zeroes
        if(zeroCount != n)
            return -1;
        
        //column check
        int oneCount = 0;
        
        for(int i=0; i<n; i++) {
            if(M[i][ans] == 1)
                oneCount++;
        }
        
        if(oneCount != n-1)
            return -1;
        
        return ans;
        
    }
};

int main()
{

    vector<vector<int>> M;
    M.push_back({0, 1, 0});
    M.push_back({0, 0, 0});
    M.push_back({0, 1, 0});

    Solution c;

    int ans = c.celebrity(M,3);

    cout << ans << endl;
}