#include <iostream>
#include <queue>
#include <map>
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

Node* createParentMapping(Node* root, int target, map<Node*, Node*> nodeToParent)
{
    Node* res = NULL;
    queue<Node*> q;
    q.push(root);

    nodeToParent[root] = NULL;

    while (!q.empty())
    {
        // int size = q.size();
        Node* front = q.front();
        q.pop();

                
        if(front->data == target)
        {
            res = front;
        }

        if(front->left)
        {
            nodeToParent[front->left] = front;
            q.push(front->left);
        }

        if(front->right)
        {
            nodeToParent[front->right] = front;
            q.push(front->right);
        }
    }
    return res;
}

int burnTree(Node* root, map<Node*, Node*> nodeToParent)
{
    queue<Node*> q;
    q.push(root);

    map<Node*, bool> visited;

    visited[root] = true;

    int ans = 0;

    while (!q.empty())
    {
        int size = q.size();
        bool flag = 0;

        for (int i = 0; i < size; i++)
        {
            Node* front = q.front();
            q.pop();

            if(front->left && !visited[front->left])
            {
                flag = 1;
                visited[front->left]= true;
                q.push(front->left);
            }

            if(front->right)
            {
                flag = 1;
                visited[front->right] = true;
                q.push(front->right);
            }

            if(nodeToParent[front] && !visited[nodeToParent[front]])
            {
                flag = 1;
                q.push(nodeToParent[front]);
                visited[nodeToParent[front]] = true;
            }
        }
        if(flag == 1)
        {
            ans++;
        }
    }
    return ans;
    
}

int minTime(Node* root, int targetData)
{
    map<Node*, Node*> nodeToParent;
    Node* target = createParentMapping(root, targetData, nodeToParent);

    int ans = burnTree(target, nodeToParent);

    return ans;
}

int main()
{

    return 0;
}