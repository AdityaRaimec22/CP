#include <bits/stdc++.h>
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

Node* insertToBST(Node* root, int data)
{
    if(root == NULL)
    {
        Node* newNode = new Node(data);
        return newNode;
    }
    
    if(root->data > data)
    {
        root->left = insertToBST(root->left, data);
        return root;
    }
    else
    {
        root->right = insertToBST(root->right, data);
        return root;
    }
}

bool searchInBST(Node* root, int d)
{
    if(root == NULL)
    {
        return false;
    }

    if (root -> data == d)
    {
        return true;
    }
    
    if (root -> data > d)
    {
        return searchInBST(root -> left, d);
    }
    else
    {
        return searchInBST(root -> right, d);
    }
}

Node* deleteNode(Node* root, int data)
{
    if(root == NULL)
    {
        return NULL;
    }

    if(root->data == data)
    {
        //0 child
        if(root->left == NULL && root->right == NULL)
        {
            delete root;
            return NULL;
        }

        // 1 child

        // left child
        if(root->left != NULL && root->right == NULL)
        {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        //right child
        if(root->right != NULL && root->left == NULL)
        {
            Node* temp = root->right;
            delete root;
            return temp;
        }

        //2 child
        if(root->left != NULL && root->right != NULL)
        {
            int mini = minVal(root->right)->data;
            root->data = mini;
            root->right = deleteNode(root->right, mini);
            return root;
        }
    }
}

Node* minVal(Node* root)
{
    if(root == NULL)
    {
        return NULL;
    }

    while (root->left != NULL)
    {
        root = root->left;
    }
    return root;
}

bool isBST(Node* root, int min, int max)
{
    if(root == NULL)
    {
        return true;
    }

    if(root->data >= min && root->data <= max)
    {
        bool left = isBST(root->left, INT_MIN, root->data);
        bool right = isBST(root->right, root->data, INT_MAX);
        return left && right;
    }
    else
        return false;
}

bool isBinaryTree(Node* root)
{
    return isBST(root, INT_MIN, INT_MAX);
}

int main()
{

    return 0;
}