#include <iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node* left = NULL;
    Node* right = NULL;

    Node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

Node* LCAinBST(Node* root, Node* P, Node* Q)
{
    if(root == NULL)
    {
        return NULL;
    }

    if(root->data > P->data && root->data > Q->data)
    {
        return LCAinBST(root->left, P, Q);
    }
    else if(root->data < P->data && root->data < Q->data)
    {
        return LCAinBST(root->right, P, Q);
    }
    else
    {
        return root;
    }
}

int main()
{
    return 0;
}