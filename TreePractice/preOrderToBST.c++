#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int d){
        this -> data = d;
        this -> left = NULL;
        this -> right = NULL;
    }
};

Node* solve(vector<int> preOrder, int mini, int max, int i)
{
    if(i > preOrder.size())
    {
        return NULL;
    }

    if(preOrder[i] < mini || preOrder[i] > max)
    {
        return NULL;
    }

    Node* root = new Node(preOrder[i++]);
    root->left = solve(preOrder, mini, root->data, i);
    root->right = solve(preOrder, root->data, max, i);
    return root;
}

Node* preOrderToBST(vector<int> &preOrder)
{
    int mini = INT_MIN;
    int max = INT_MAX;
    int i = 0;
    return solve(preOrder, mini, max, i);
}

int main()
{

    return 0;
}