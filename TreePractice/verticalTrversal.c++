#include <iostream>
#include <vector>
#include <map>
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

vector<int> vertical(Node* root)
{
    map<int, map<int, vector<int> > > mp;
    queue<pair<Node*, pair<int, int> > > q;
    vector<int> ans;

    if(root == NULL)
    {
        return ans;
    }

    q.push(make_pair(root, make_pair(0, 0)));

    while (!q.empty())
    {
        pair<Node*, pair<int, int> > p = q.front();
        q.pop();

        Node* frontNode = p.first;
        int hd = p.second.first;
        int lvl = p.second.second;

        mp[hd][lvl].push_back(frontNode->data);

        if(frontNode->left)
            q.push(make_pair(frontNode->left, make_pair(hd-1, lvl+1)));

        if(frontNode->right)
            q.push(make_pair(frontNode->right, make_pair(hd+1, lvl+1)));
    }

    for(auto i: mp)
        for(auto j: i.second)
            for(auto k: j.second)
                ans.push_back(k);

    return ans;
}

int main()
{

    return 0;
}