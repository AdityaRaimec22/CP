#include <iostream>
#include <vector>
#include <queue>
#include <map>
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

vector<int> topView(Node* root)
{
    vector<int> ans;
    map<int, int> topNode;
    queue<pair<Node*, int> > q;

    if(root == NULL)
    {
        return ans;
    }

    q.push(make_pair(root, 0));

    while (!q.empty())
    {
        pair<Node*, int> frontNode = q.front();
        q.pop();

        Node* frontNode1 = frontNode.first;
        int hd = frontNode.second;

        if(topNode.find(hd) == topNode.end()) //Remove this check for bottom view
            topNode[hd] = frontNode1 -> data;

        if(frontNode1->left)
            q.push(make_pair(frontNode1->left, hd-1));

        if(frontNode1->right)
            q.push(make_pair(frontNode1->right, hd+1));
    }

    for(auto i: topNode)
    {
        ans.push_back(i.second);
    }

    return ans;
}

int main()
{

    return 0;
}