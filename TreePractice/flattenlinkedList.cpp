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

void flatten(Node* root)
{
    Node* curr = root;
    while (curr)
    {
        if(curr->left != NULL)
        {
            Node* pred = curr->left;
            while (pred->right)
            {
                pred = pred->right;
            }
            
            pred->right = curr->right;
            curr->right = curr->left;
            curr->left = NULL;
        }
        curr = curr->right;
    }
}

int main()
{

    return 0;
}