#include <iostream>
#include <vector>
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

void solve(Node* root, vector<int> ans, int count, int k)
{
    if(root == NULL)
    {
        return;
    }

    ans.push_back(root->data);

    solve(root->left, ans, count, k);
    solve(root->right, ans, count, k);

    int size = ans.size();
    int sum = 0;
    for(int i = size-1; i >= 0; i--)
    {
        sum += ans[i];
        if(sum == k)
            count++;
    }

    ans.pop_back();
}

int sumK(Node* root, int k)
{
    vector<int> ans;
    int count = 0;
    solve(root, ans, count, k);
    return count;
}

int main()
{

    return 0;
}