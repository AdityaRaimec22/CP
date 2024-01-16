#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    int row;
    int col;

    Node(int data, int row, int col)
    {
        this->data = data;
        this->row = row;
        this->col = col;
    }
};

class Compare{
    public:
    bool operator()(Node* a, Node* b)
    {
        return a->data > b->data;
    }
};

vector<int> mergeKSortedArrays(vector<vector<int>> &kArrays, int k)
{
    priority_queue<Node*, vector<Node*>, Compare> minHeap;

    for(int i = 0; i < k; i++)
    {
        Node* tmp = new Node(kArrays[i][0], i, 0);
        minHeap.push(tmp);
    }

    vector<int> ans;

    while(minHeap.size() > 0)
    {
        Node* next = minHeap.top();
        minHeap.pop();

        ans.push_back(next->data);
        int row = next->row;
        int col = next->col;

        if(col+1 < kArrays.size())
        {
            Node* nextTmp = new Node(kArrays[row][col+1], row, col+1);
            minHeap.push(nextTmp);
        }
    }

    return ans;
}

int main(){


    return 0;
}