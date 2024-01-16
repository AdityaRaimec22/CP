#include <iostream>
#include <vector>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

void storeInorder(Node* root, vector<int> &v)
{
    if(root == NULL)
    {
        return;
    }

    storeInorder(root->left, v);
    v.push_back(root->data);
    storeInorder(root->right, v);
}

void fillInorder(Node* root, vector<int> &v, int index)
{
    if(root == NULL)
    {
        return;
    }

    root->data = v[index++];

    fillInorder(root->left, v, index);
    fillInorder(root->left, v, index);
}

Node* BSTtoMinHeap(Node* root)
{
    vector<int> v;
    storeInorder(root, v);
    fillInorder(root, v, 0);
    return root;
}

int main()
{

    return 0;
}