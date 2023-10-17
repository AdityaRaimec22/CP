#include <iostream>
#include <stack>
#include <climits>
#define Max 1000
using namespace std;

class Solution
{
    public:
    int maxRectangle(int M[Max][Max], int n, int m)
    {
        int area = largestRectangleArea(M[0], m);

        for(int i = 1; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(M[i][j] != 0)
                {
                    M[i][j] = M[i][j] + M[i-1][j];
                }
                else
                {
                    M[i][j] = 0;
                }
            }
            area = max(area, largestRectangleArea(M[i],m));
        }
        return area;
    }
};