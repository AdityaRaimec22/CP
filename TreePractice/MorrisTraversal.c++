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

void MorrisTraversal(Node* root)
{
    while (root)
    {
        if(root->left == NULL)
        {
            cout<< root->data << " ";
            root = root->right;
        }
        else
        {
            Node* curreent = root->left;
            while (root->right && root->right != root)
            {
                curreent = curreent->right;
            }
            
            if(curreent->right == root)
            {
                curreent->right=NULL;
                root=root->right;
            }
            else
            {
                cout << root->data << " ";
                curreent->right = root;
                root = root->left;
            }
        }
    }
}

int main()
{

    return 0;
}