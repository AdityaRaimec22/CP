#include <iostream>
#include <climits>
using namespace std;

class Node{
    public:
    Node* left;
    Node* right;
    int data;

    Node(int data)
    {
        this->data = data;
        this->right = NULL;
        this->left = NULL;
    }

};

class Info{
    public:
    int max;
    int mini;
    bool isBST;
    int size;
};

Info solve(Node* root, int maxSize)
{
    if(root == NULL)
    {
        return {INT_MIN, INT_MAX, true, 0};
    }

    Info left = solve(root->left, maxSize);
    Info right = solve(root->right, maxSize);

    Info currNode;

    currNode.size = left.size + right.size + 1;
    currNode.max = max(root->data, right.max);
    currNode.mini = min(root->data, left.mini);

    if(left.isBST && right.isBST && (root->data > left.max && root->data < right.mini))
    {
        currNode.isBST = true;
    }
    else
    {
        currNode.isBST = false;
    }

    if(currNode.isBST)
    {
        maxSize = max(maxSize, currNode.size);
    }

    return currNode;
}

int largestBST(Node* root)
{
    int maxSize = 0;
    Info root = solve(root, maxSize);
    return maxSize;
}

int main()
{

    return 0;
}