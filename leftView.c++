#include <iostream>
#include <vector>
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

void solve(Node* root, vector<int> &ans, int level)
{
    if(root == NULL)
    {
        return;
    }

    if(level == ans.size())
        ans.push_back(root->data);

    solve(root->left, ans, level+1);
    solve(root->right, ans, level+1);
}

vector<int> leftView(Node* root)
{
    vector<int> ans;
    solve(root, ans, 0);
    return ans;
}

int main()
{

    return 0;
}