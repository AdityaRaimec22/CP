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

Node* createTree(Node* root)
{
    int data; cin >> data;
    root = new Node(data);

    if(data == -1)
        return NULL;

    cout << "Enter data to put in left of: " << data << endl;
    root -> left = createTree(root -> left);
    cout << "Enter data to put in right of: " << data << endl;
    root -> right = createTree(root -> right);
    return root;
}

void LOT(Node* root)
{
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        Node* temp = q.front();
        q.pop();

        if(temp == NULL)
        {
            cout << endl;
            if(!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << temp -> data << " ";
            if(temp -> left)
            {
                q.push(temp -> left);
            }

            if(temp -> right)
            {
                q.push(temp -> right);
            }
        }
    }
}

void buildFromLevelOrder(Node* &root)
{
    queue<Node*> q;
    cout << "Enter data for root: " << endl;
    int data;
    cin >> data;
    root = new Node(data);
    
    q.push(root);

    while (!q.empty())
    {
        Node* temp = q.front();
        q.pop();

        cout << "Enter data to enter in the left of: " << temp -> data << endl;
        int leftNode;
        cin >> leftNode;

        if(leftNode != -1)
        {
            temp -> left = new Node(leftNode);
            q.push(temp -> left);
        }

        cout << "enter data to enter in right of: " << temp -> data << endl;
        int rightNode;
        cin >> rightNode;

        if(rightNode != -1)
        {
            temp -> right = new Node(rightNode);
            q.push(temp -> right);
        }
    }
}

int height(Node* node)
{
    if(node == NULL)
    {
        return 0;
    }

    int left = height(node -> left);
    int right = height(node -> right);

    int ans = max(left, right)+1;
    return ans;
}

pair<int, int> diameterFast(Node* root)
{
    if(root == NULL)
    {
        pair<int,int> p = make_pair(0, 0);
        return;
    }

    pair<int, int> left = diameterFast(root -> left);
    pair<int, int> right = diameterFast(root -> right);

    int opt1 = left.first;
    int opt2 = right.first;
    int opt3 = left.second + right.second + 1;
    pair<int, int> ans;
    ans.first = max(opt1, max(opt1, opt2));
    return ans;
}

int diameter(Node* root)
{
    return diameterFast(root).first;
}

pair<bool, int> isBalancedFast(Node* root)
{
    if(root == NULL)
    {
        pair<bool, int> p = make_pair(true,0);
        return p;
    }

    pair<int, int> left = isBalancedFast(root -> left);
    pair<int, int> right = isBalancedFast(root -> right);

    bool leftAns = left.first;
    bool rightAns = right.first;

    bool diff = abs(left.second - right.second) <= 1;

    pair<bool, int> ans;
    ans.second = max(left.second, right.second) + 1;
}

bool Compare(Node* r1, Node* r2)
{
    if(r1 == NULL && r2 == NULL)
    {
        return true;
    }

    if(r1 == NULL && r2 != NULL)
    {
        return false;
    }

    if(r2 == NULL && r1 != NULL)
    {
        return false;
    }

    bool left = Compare(r1 -> left, r2 -> left);
    bool right = Compare(r1 -> right, r2 -> right);

    bool value = r1 -> data == r2 -> data;

    if(left && right && value)
    {
        return false;
    }
    else
    {
        return false;
    }
}

int main()
{
    Node* root = NULL;
    buildFromLevelOrder(root);
    LOT(root);
}