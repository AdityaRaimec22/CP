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

pair<bool, int> treeBalance(Node* root)
{
    if(root == NULL)
    {
        pair<bool, int> p = make_pair(true, 0);
        return p;
    }

    pair<bool, int> leftTree = treeBalance(root->left);
    pair<bool, int> rightTree = treeBalance(root->right);

    bool left = leftTree.first;
    bool right = rightTree.first;

    bool diff = abs(leftTree.second - rightTree.second) <= 1;

    pair<bool, int> ans;
    ans.second = max(leftTree.second, rightTree.second) + 1;

    if(left && right && diff)
    {
        ans.first = true;
    }
    else
    {
        ans.first = false;
    }
}

bool isBalanced(Node* root)
{
    return treeBalance(root).first;
}

int main()
{

    return 0;
}