#include<bits/stdc++.h>
using namespace std;

class Node {
    public:
    int data;
    int i;
    int j;

    Node(int data, int row, int col)
    {
        this -> data = data;
        this->i = row;
        this->j = col;
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

    for (int i = 0; i < k; i++)
    {
        Node* tmp = new Node(kArrays[i][0], i, 0);
        minHeap.push(tmp);
    }

    vector<int> ans;

    while(minHeap.size() > 0)
    {
        Node* tmp = minHeap.top();

        ans.push_back(tmp->data);
        minHeap.pop();

        int i = tmp->i;
        int j = tmp->j;

        if(j+1 < kArrays.size())
        {
            Node* next = new Node(kArrays[i][j+1], i, j+1);
            minHeap.push(next);
        }
    }
    return ans;
}

int main(){
    
    return 0;
}