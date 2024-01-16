#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

int countNodes(Node* root)
{
    if(root == NULL)
        return 0;

    int left = countNodes(root->left);
    int right = countNodes(root->right);
    return 1 + left + right;
}

bool isCBT(Node* root, int index, int totalNodes)
{
    if(root == NULL)
    {
        return NULL;
    }

    if(index > totalNodes)
    {
        return false;
    }
    else
    {
        int left = isCBT(root, 2*index + 1, totalNodes);
        int right = isCBT(root, 2*index + 2, totalNodes);
        return (left && right);
    }
}

bool inOrder(Node* root)
{
    if(root == NULL)
    {
        return NULL;
    }

    if(root->left == NULL && root->right == NULL)
    {
        return true;
    }
    if(root->right == NULL && root->data > root->left->data)
    {
        return true;
    }
    else
    {
        bool left = inOrder(root->left);
        bool right = inOrder(root->right);

        return (left && right && 
        root->data > root->left->data && root->data > root->right->data);
    }
}

bool isBinaryTreeHeap(Node* root)
{
    int index = 0;
    int totalNodes = countNodes(root);
    if(isCBT(root, index, totalNodes) && inOrder(root))
        return true;
    else
        return false;
}

int main()
{
    cout << "hello" << endl;
    return 0;
}