#include <iostream>
#include <queue>
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

vector<int> zigZag(Node* root)
{
    vector<int> result;
    queue<Node*> q;
    bool leftToRight = true;

    q.push(root);

    while (!q.empty())
    {
        int size = q.size();
        vector<int> ans(size);

        for (int i = 0; i < size; i++)
        {
            Node* frontNode = q.front();
            q.pop();
            
            int index = leftToRight ? i : size - i - 1;

            ans[index] = frontNode->data;

            if(frontNode -> left)
                q.push(frontNode->left);

            if(frontNode->right)
                q.push(frontNode->right);
        }

        for(auto i: ans)
            result.push_back(i);

        leftToRight = !leftToRight;
    }
    return result;
}

int main()
{

    return 0;
}