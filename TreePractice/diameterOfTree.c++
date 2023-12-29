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

pair<int, int> findDiameter(Node* root)
{
    if(root == NULL)
    {
        pair<int, int> p = make_pair(0, 0);
        return p;
    }

    pair<int, int> left = findDiameter(root->left);
    pair<int, int> right = findDiameter(root->right);

    int op1 = left.first;
    int op2 = right.first;
    int op3 = left.second + right.second + 1;

    pair<int, int> ans;
    ans.first = max(op1, max(op2, op3));
    ans.second = max(left.second, right.second) + 1;

    return ans;
}

int diameter(Node* root)
{
    return findDiameter(root).first;
}

int main()
{

    return 0;
}