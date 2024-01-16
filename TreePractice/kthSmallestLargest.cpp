#include <iostream>
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

int solve(Node* root, int i, int k)
{
    if(root == NULL)
    {
        return -1;
    }

    //L
    int left = solve(root->left, i, k);

    if(left != -1)
    {
        return left;
    }

    //N
    i++;
    if(i == k)
        return root->data;

    //R
    return solve(root->right, i, k);
}

int kthSmallestLargest(Node* root, int k)
{
    int i = 0;
    int ans = solve(root, i, k);
    return ans;
}

int main()
{

    return 0;
}