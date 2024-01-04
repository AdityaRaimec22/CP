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

int findPosition(int in[], int element, int n)
{
    for (int i = 0; i < n; i++)
    {
        if(in[i] == element)
        {
            return i;
        }
    }
    return -1;
}

Node* solve(int in[], int pre[], int index, int indexStart, int indexxEnd, int n)
{
    if(index >= n || indexStart > indexxEnd)
    {
        return NULL;
    }

    int element = pre[index++];
    Node* root = new Node(element);
    int position = findPosition(in, element, n);

    root->left = solve(in, pre, index, indexStart, position-1, n);
    root->right = solve(in, pre, index, position+1, indexxEnd, n);

    return root;
}

Node* inorderPreOrder(int in[], int pre[], int n)
{
    int preOrderIndex = 0;
    Node* ans = solve(in, pre, preOrderIndex, 0, n-1, n);
    return ans;
}

int main()
{

    return 0;
}