#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    Node* left;
    Node* right;
    int data;

    Node(int data)
    {
        this->data = data;
        this->right = NULL;
        this->left = NULL;
    }

};

int countNodes(Node* root)
{
    if (root == NULL)
    {
        return 0;
    }
    
    int ans = 1 + countNodes(root -> left) + countNodes(root -> right);
    return ans;
}

bool isCBT(Node* root, int index, int cnt)
{
    if (root == NULL)
    {
        return true;
    }

    if (index >= cnt)
    {
        return false;
    }
    
    else
    {
        bool left = isCBT(root -> left, 2*index, cnt);
        bool right = isCBT(root -> right, 2*index + 2, cnt);
        return (left && right);
    }
}

bool isMaxOrder(Node* root)
{
    //leaf node
    if (root -> left == NULL && root -> right == NULL)
    {
        return true;
    }

    if (root -> right == NULL)
    {
        return (root -> data > root -> left -> data);
    }
    else
    {
        bool left = isMaxOrder(root -> left);
        bool right = isMaxOrder(root -> right);

        return (left && 
                right && 
                (root -> data > root -> left -> data && 
                root -> data > root -> right -> data)
            );
    }
    
    
}

int getKthLargest(vector<int> &arr, int k)
{
    vector<int> sumStore;
    int n = arr.size();

    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += arr[j];
            sumStore.push_back(sum);
        }
        
    }

    sort(sumStore.begin(), sumStore.end());

    return sumStore[sumStore.size() - k];
    
}

int main(){

    
    return 0;
}