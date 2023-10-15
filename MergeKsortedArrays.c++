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
        i = row;
        j = col;
    }
};

class Compare{
    public:
    bool operator()(Node* a, Node* b)
    {
        return a->data > b->data;
    }
};

vector<int> mergeKSortedArrays(vector<vector<int>>, int k)
{
    priority_queue<Node*, vector<Node*>, Compare> minHeap;

    for (int i = 0; i < k; i++)
    {
        Node* tmp = new Node(kArrays[i][0], i, 0);
        minHeap.push(tmp);
    }
}

int main(){
    
    return 0;
}