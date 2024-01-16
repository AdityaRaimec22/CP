#include <iostream>
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

pair<int, int> predecessorSuccessor(Node* root, int key)
{
    Node* temp = root;
    int pred = -1;
    int succ = -1;

    while (temp->data != key)
    {
        if(temp->data > key)
        {
            temp = temp->left;
            succ = temp->data;
        }
        else
        {
            temp = temp->right;
            pred = temp->data;
        }
    }

    // pred and succ

    // pred
    Node* leftTree = temp->left;
    while (leftTree != NULL)
    {
        pred = leftTree->data;
        leftTree = leftTree->right;
    }
    
    //succ
    Node* rightTree = temp->right;
    while (rightTree != NULL)
    {
        succ = rightTree->data;
        rightTree = rightTree->left;
    }
    
    pair<int, int> ans = make_pair(pred, succ);
    return ans;
    
}

int main()
{

    return 0;
}