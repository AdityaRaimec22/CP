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

    Node* newRoot = new Node(inOrder[0]);

    Node* curr = newRoot;

    for(int i = 1; i < n; i++)
    {
        Node* temp = new Node(inOrder[i]);
        curr->left = NULL;
        curr->right = temp;
        curr = temp;
    }

    curr->left = NULL;
    curr->right = NULL;

    return newRoot;
}

int main()
{

    return 0;
}