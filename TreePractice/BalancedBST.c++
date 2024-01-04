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

void printInorder(Node* root, vector<int> &inOrder)
{
    if(root == NULL)
    {
        return;
    }

    printInorder(root->left, inOrder);
    inOrder.push_back(root->data);
    printInorder(root->right, inOrder);
}

Node* flattenBST(Node* root)
{
    vector<int> inOrder;
    printInorder(root, inOrder);
    int n = inOrder.size()-1;

    return createBalancedBST(0, n, inOrder);
}

Node* createBalancedBST(int s, int e, vector<int> inOrder)
{
    if(s>e)
    {
        return NULL;
    }
    int mid = (s+e)/2;
    Node* newNode = new Node(inOrder[mid]);
    newNode->left = createBalancedBST(0,mid-1, inOrder);
    newNode->right = createBalancedBST(mid+1, e, inOrder);
    return newNode;
}