#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int d){
        this -> data = d;
        this -> left = NULL;
        this -> right = NULL;
    }
};

void printInorder(Node* root, vector<int> &inOrder)
{
    if(root == NULL)
    {
        return;
    }

    printInorder(root->left, inOrder);
    inOrder.push_back(root->data);
    printInorder(root->right, inOrder);
}

bool twoSumInBST(Node* root, int num)
{
    vector<int> inOrder;
    printInorder(root, inOrder);
    int i = 0, j = inOrder.size()-1;

    int sum = 0;
    while (i<j)
    {
        sum = inOrder[i] + inOrder[j];
        if(sum == num)
        {
            return true;
        }
        else if (sum > num)
        {
            j--;
        }
        else
        {
            i++;
        }
    }
    return false;
}

int main()
{

    return 0;
}