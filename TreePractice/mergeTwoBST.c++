#include <bits/stdc++.h>
using namespace std;

class Node
{
    public:
    int data;
    Node* left = NULL;
    Node* right = NULL;

    Node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

void storeInorder(Node* root, vector<int> inorderVal)
{
    if (root == NULL)
    {
        return;
    }

    storeInorder(root -> left, inorderVal);
    inorderVal.push_back(root -> data);
    storeInorder(root -> right, inorderVal);
    
}

vector<int> mergeTwoArray(vector<int> t1, vector<int> t2, vector<int> ans)
{
    int i =0, j = 0, k = 0;
    while(i < t1.size() && j < t2.size())
    {
        if(t1[i] < t2[j])
        {
            ans[k++] = t1[i];
            i++;
        }
        else
        {
            ans[k++] = t2[j];
            j++;
        }
    }

    while(i < t1.size())
    {
        ans[k++] = t1[i];
        i++;
    }

    while (j < t2.size())
    {
        ans[k++] = t2[j];
        j++;
    }
    
    return ans;
}

Node* inorderToTree(int s, int e, vector<int> mergeArray)
{
    if(s>e)
    {
        return NULL;
    }

    int mid = (s+e)/2;

    Node* root = new Node(mergeArray[mid]);
    root->left = inorderToTree(s, mid-1, mergeArray);
    root->right = inorderToTree(s+1, e, mergeArray);
    return root;
}

Node* mergeBST(Node* bst1, Node* bst2)
{
    vector<int> ans;
    vector<int> t1;
    vector<int> t2;
    storeInorder(bst1, t1);
    storeInorder(bst2, t2);

    vector<int> mergeArray = mergeTwoArray(t1, t2, ans);
    int s = 0, e = mergeArray.size()-1;
    return inorderToTree(s, e, mergeArray);
}

int main()
{

    return 0;
}