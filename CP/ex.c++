#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define f(i,j,n) for(int i=j; i<n; i++)
#define fo(i,j) for(auto i: j)
#define vec vector<int>

struct Item{
    int value;
    int weight;
};

class cpm{
    public:
    bool operator()(pair<int, pair<int, int> > &a, pair<int, pair<int, int> > &b) {
        return a.first < b.first;
    }
};

class Solution
{
    public:
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        // Your code here.
        priority_queue<pair<int, pair<int, int> >, vector<pair<int, pair<int, int> > >, cpm> pq;
        
        for(int i = 0; i < n; i++) {
            double val = static_cast<double>(arr[i].value/arr[i].weight);
            pq.push(make_pair(val, make_pair(arr[i].value, arr[i].weight)));
        }
        double ans = 0;
        while (!pq.empty() && W != 0)
        {
            auto top = pq.top();
            pq.pop();

            if(W >= top.second.second) {
                W = W - top.second.second;
                ans += top.second.first;
            } else {
                ans += W*top.first;
                break;
            }
        }
        return ans;
    }
};

int main(){
    Item items[] = {
        {60, 10},  // Item 1: value = 10, weight = 5
        {100, 20},  // Item 2: value = 15, weight = 8
        {120, 30} // Item 3: value = 20, weight = 6  // Item 5: value = 12, weight = 9
    };

    Solution s;
    int w = 50;
    int n = 3;

    cout << s.fractionalKnapsack(w,items,n) << endl;

    return 0;
}