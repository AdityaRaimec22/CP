#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define f(i,j,n) for(int i=j; i<n; i++)
#define fo(i,j) for(auto i: j)
#define vec vector<int>

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    private:
    int solve(int start[], int end[], int n, int index, int prev) {
        if(index == n) {
            return 0;
        }
        
        int include = 0;
        if(start[index] > prev){
            // v.push_back(end[index]);
            include = 1 + solve(start, end, n, index+1, end[index]);
        }
        int exclude = 0 + solve(start, end, n, index+1, prev);

        return max(include, exclude);
    }
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    int maxMeetings(int start[], int end[], int n)
    {
        // Your code her
        return solve(start, end, n, 0, -1);
    }
};

int main(){
    int end[] = {6, 7, 8, 9};
    int start[] = {1, 2, 3, 4};
    int n = 4;
    Solution s;
    cout << s.maxMeetings(start, end, n) << endl;
    
    return 0;
}
