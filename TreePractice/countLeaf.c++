#include  <iostream>
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

void count(Node* &node, int &cnt)
{
    if(node == NULL)
    {
        return;
    }

    count(node->left, cnt);

    if(node->left == NULL && node->right == NULL)
    {
        cnt++;
    }

    count(node->right, cnt);
}

int countLeaf(Node* node)
{
    int cnt = 0;
    count(node, cnt);
    return cnt;
}

int main()
{

    return 0;
}