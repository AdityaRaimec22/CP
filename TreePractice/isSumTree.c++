#include <iostream>
using namespace std;

class Node{
    
    public:

    Node* left;
    Node* right;
    int data;

    Node(int d)
    {
        this -> left = NULL;
        this -> right = NULL;
        this -> data = d;
    }
};

pair<bool, int> isSumTreeFast(Node* root)
{
    if (root == NULL)
    {
        pair<bool, int> p = make_pair(true, 0);
        return p;
    }

    if (root->left == NULL && root->right == NULL)
    {
        pair<bool, int> p = make_pair(true, root->data);
        return p;
    }

    pair<bool, int> leftSumTree = isSumTreeFast(root->left);
    pair<bool, int> rightSumTree = isSumTreeFast(root->right);

    bool isLeftSumTree = leftSumTree.second;
    bool isRightSumTree = rightSumTree.second;

    int leftSum = leftSumTree.first;
    int rightSum = rightSumTree.first;

    bool condn = root->data == leftSum + rightSum;

    pair<bool, int> ans;

    if(isLeftSumTree && isRightSumTree && condn)    
    {
        ans.first = true;
        ans.second = root->data + leftSum + rightSum;
    }
    else
    {
        ans.first = false;
    }
    return ans;
}

bool isSumTree(Node* root)
{
    return isSumTreeFast(root).first;
}

int main()
{

    return 0;
}