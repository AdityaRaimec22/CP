#include <iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int d)
    {
        this -> data = d;
        this -> left = NULL;
        this -> right = NULL;
    }
};

void solve(Node* root, int len, int &maxLen, int sum, int &maxSum)
{
    if(root == NULL)
    {
        if(len > maxLen)
        {
            maxLen = len;
            maxSum = sum;
        }
        else if(len == maxLen)
        {
            maxSum = sum;
        }
        return;
    }

    sum += root->data;

    solve(root->left, len, maxLen, sum, maxSum);
    solve(root->right, len, maxLen, sum, maxSum);
}

int sumOfLongRoot(Node* root)
{
    int len = 0;
    int maxLen = 0;

    int sum = 0;
    int maxSum = 0;

    solve(root, len, maxLen, sum, maxSum);

    return maxSum;
}

int main()
{

    return 0;
}