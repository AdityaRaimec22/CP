#include<iostream>
#include<vector>
#include<map>
#include<queue>
#include<climits>
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

class Solution{
    public:
    void leftTree(Node* root, vector<int> &ans){
        if((root == NULL) || (root -> right == NULL && root->left == NULL))
        {
            return;
        }
        ans.push_back(root->data);
        if (root -> left)
        {
            leftTree(root->left, ans);
        } else {
            leftTree(root->right, ans);
        }
        
    }

    void rightTree(Node* root, vector<int> &ans)
    {
        if ((root == NULL) || (root -> left == NULL && root -> right == NULL))
        {
            return;
        }

        if (root -> right)
        {
            rightTree(root -> left, ans);
        } else {
            rightTree(root -> left, ans);
        }

        ans.push_back(root -> data);
    }

    void leafs(Node* root, vector<int> &ans)
    {
        if(root == NULL)
        {
            return;
        }

        if(root->left == NULL && root->right == NULL)
        {
            ans.push_back(root -> data);
            return;
        }

        leafs(root -> left, ans);
        leafs(root->right, ans);
    }

    vector<int> verticalOrder(Node* root)
    {
        map<int, map<int, vector<int> > > nodes;
        queue<pair<Node* , pair<int, int> > > q;
        vector<int> ans;

        if(root == NULL)
        { return ans;}

        q.push(make_pair(root, make_pair(0,0)));

        while (!q.empty())
        {
            pair<Node* , pair<int, int>> temp = q.front();
            q.pop();

            Node* frontNode = temp.first;
            int hd = temp.second.first;
            int lvl = temp.second.second;

            nodes[hd][lvl].push_back(frontNode->data);

            if (frontNode->left)
            {
                q.push(make_pair(frontNode->left,make_pair(hd-1, lvl+1)));
            }

            if (frontNode->right)
            {
                q.push(make_pair(frontNode->right, make_pair(hd+1, lvl+1)));
            }
            
            
        }
        for(auto i:nodes)
        {
            for(auto j:i.second)
            {
                for(auto k:j.second)
                {
                    ans.push_back(k);
                }
            }
        }
        return ans;
        
    }

    vector<int> topView(Node* root)
    {
        vector<int> ans;
        if(root == NULL)
        {
            return ans;
        }

        map<int, int> topNodes;
        queue<pair<Node*, int>> q;

        q.push(make_pair(root, 0));

        while (!q.empty())
        {
            pair<Node*, int> temp = q.front();
            q.pop();
            Node* frontNode = temp.first;
            int hd = temp.second;

            if(frontNode->left)
                q.push(make_pair(frontNode->left, hd-1));
            if(frontNode->right)
                q.push(make_pair(frontNode->right, hd+1));
        }
        for(auto i:topNodes)
        {
            ans.push_back(i.second);
        }
        return ans;
    }

    void solve(Node* root, int k, int count, vector<int> path)
    {
        if(root == NULL)
            return;

        path.push_back(root->data);

        solve(root->left, k, count, path);
        solve(root->right, k, count, path);

        int sum = 0;
        int size = path.size();
        for(int i = 0; i < size; i++)
        {
            sum+=path[i];
            if(sum == k)
                count++;
        }

        path.pop_back();
    }

    int sumK(Node* root, int k)
    {
        vector<int> path;
        int count = 0;
        solve(root, k, count, path);
        return count;
    }

    Node* lca(Node* root, int n1, int n2)
    {
        if(root == NULL)
        {
            return NULL;
        }

        if(root -> data == n1 || root -> data == n2)
        {
            return root;
        }

        Node* leftAns = lca(root->left, n1, n2);
        Node* rightAns = lca(root->right, n1, n2);

        if(leftAns != NULL && rightAns != NULL)
        {
            return root;
        }
        else if(leftAns != NULL && rightAns == NULL)
            return leftAns;
        else if(leftAns == NULL && rightAns != NULL)
            return rightAns;
        else
            return NULL;
    }

    pair<int, int> solve(Node* root)
    {
        if(root == NULL)
        {
            pair<int, int> p = make_pair(0,0);
            return p;
        }

        pair<int, int> left = solve(root->left);
        pair<int, int> right = solve(root->right);

        pair<int, int> res;

        res.first = root->data + left.second + right.second;

        res.second = max(left.first, left.second) + max(right.first , right.second);

        return res;
    }

    int getMaxSum(Node* root)
    {
        pair<int, int> ans = solve(root);
        return max(ans.first, ans.second);
    }

    int findPosition(int in[], int element, int n)
    {
        for (int i = 0; i < n; i++)
        {
            if (in[i] == element)
            {
                return i;
            }
        }
        return -1;
        
    }

    void createNodeToIndexMapping(int in[], int n, map<int, int> &nodeToIndex)
    {
        for (int i = 0; i < n; i++)
        {
            nodeToIndex[in[i]] == i;
        }
    }

    Node* solve(int in[], int pre[], int index, int inorderStart, int inorderEnd, int n, map<int, int> nodeToIndex)
    {
        if(index >= n || inorderStart > inorderEnd)
        {
            return NULL;
        }

        int element = pre[index++];
        Node* root = new Node(element);
        // find position of element using map
        int position = nodeToIndex[element];
        // findPosition(in, element, n);

        root->left = solve(in, pre, index, inorderStart, position-1, n, nodeToIndex);
        root->right = solve(in, pre, index, position+1, inorderEnd,n, nodeToIndex);

        return root;
    }

    Node* buildTree(int in[], int pre[], int n)
    {
        int preOrderIndex = 0;
        map<int, int> nodeToIndex;
        createNodeToIndexMapping(in, n, nodeToIndex);
        Node* ans = solve(in, pre, preOrderIndex, 0, n-1, n, nodeToIndex);
        return ans;
    }

    Node* createParentMapping(Node* root, int target, map<Node*, Node*> &nodeToParent )
    {
        Node* res = NULL;

        queue<Node*> q;
        q.push(root);
        nodeToParent[root] = NULL;

        while (!q.empty())
        {
            Node* front = q.front();
            q.pop();

            if (front->data == target)
            {
                res = front;
            }

            if (front->left)
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

    int burnTree(Node* root ,map<Node*, Node*> &nodeToParent)
    {
        map<Node*, bool> visited;
        queue<Node*> q;

        q.push(root);
        visited[root] = true;

        int ans = 0;

        while (!q.empty())
        {
            bool flag = 0;
            int size = q.size();
            for (int i = 0; i < size; i++)
            {
                Node* front = q.front();
                q.pop();

                if (front->left && !visited[front -> left])
                {
                    flag = 1;
                    q.push(front->left);
                    visited[front->left] = true;
                }
                if (front->right && !visited[front->right])
                {
                    flag = 1;
                    q.push(front->right);
                    visited[front->right] = true;
                }

                if (nodeToParent[front] && !visited[nodeToParent[front]])
                {
                    flag = 1;
                    q.push(nodeToParent[front]);
                    visited[nodeToParent[front]] = 1;
                }
            }
            if (flag = 1)
            {
                ans++;
            }
        }
        return ans;
    }

    int minTime(Node* root, int target)
    {
        map<Node*, Node*> nodeToParent;
        Node* targetNode = createParentMapping(root, target, nodeToParent);

        int ans = burnTree(targetNode, nodeToParent);

        return ans; 
    }
};

Node* insertToBST(Node* root, int data)
{
    if(root == NULL)
    {
        root = new Node(data);
        return root;
    }

    if(data > root -> data)
    {
        root -> right = insertToBST(root -> right, data);
    }
    else
    {
        root -> left = insertToBST(root -> left, data);
    }

    return root;
}

void takeInput(Node* &root){
    int data;
    cin>>data;

    while (data != -1)
    {
        root = insertToBST(root, data);
        cin>>data;
    }
}

bool searchInBST(Node* root, int d)
{
    if(root == NULL)
    {
        return false;
    }

    if (root -> data == d)
    {
        return true;
    }
    
    if (root -> data > d)
    {
        return searchInBST(root -> left, d);
    }
    else
    {
        return searchInBST(root -> right, d);
    }
    
}

int minVal(Node* root)
{
    if (root == NULL)
    {
        return NULL;
    }

    while (root -> left != NULL)
    {
        root = root -> left;
    }
    
    return root -> data;
    
}

Node* deleteFromBST(Node* root, int data)
{
    if (root == NULL)
    {
        return NULL;
    }

    if (root -> data == data)
    {
        //0 child
        if (root -> left == NULL && root -> right == NULL)
        {
            delete root;
            return NULL;
        }

        // 1 child

        //left child
        if (root -> left != NULL && root -> right == NULL)
        {
            Node* temp = root -> left;
            delete root;
            return temp;
        }

        //right child
        if (root -> left == NULL && root -> right != NULL)
        {
            Node* temp = root -> right;
            delete root;
            return temp;
        }
        
        //2 child
        if (root -> left != NULL && root -> right != NULL)
        {
            int mini = minVal(root -> right);
            root -> data = mini;
            root -> right = deleteFromBST(root -> right, mini);
            return root;
        }
    }
    else if(root->data > data)
    {
        root->left = deleteFromBST(root->left, data);
        return root;
    }
    else
    {
        root->right = deleteFromBST(root->right, data);
        return root;
    }
}

bool isBST(Node* root, int min, int max)
{
    if(root == NULL)
        return true;

    if (root -> data >= min && root -> data <= max)
    {
        bool left = isBST(root -> left, min, root -> data);
        bool right = isBST(root -> right, root -> data, max);
        return left && right;
    }
    else
        return false;
    
}

bool isBinaryTree(Node* root)
{
    isBST(root, INT_MIN, INT_MAX);
}

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

bool twoSumInBST(Node* root, int target)
{
    vector<int> inorderVal;
    storeInorder(root, inorderVal);
    int i = 0, j = inorderVal.size() - 1;

    while (i<j)
    {
        int sum = inorderVal[i] + inorderVal[j];
        if (sum == target)
        {
            return true;
        }
        else if (sum > target)
        {
            j--;
        }
        else
        {
            i++;
        }
    }
    return false;
}

Node* inorderToBST(int s, int e, vector<int> in)
{   
    //base case
    if (s>e)
    {
        return NULL;
    }

    int mid = (s+e)/2;
    Node* root = new Node(in[mid]);
    root -> left = inorderToBST(s, mid - 1, in);
    root -> right = inorderToBST(mid + 1, e, in);
    return root;
}

vector<int> mergeArrays(vector<int> bst1, vector<int> bst2, vector<int> ans)
{
    int i = 0, j = 0, k = 0;
    while (i < bst1.size() && j < bst2.size())
    {
        if (bst1[i] < bst2[j])
        {
            ans[k++] = bst1[i];
            i++;
        }
        else
        {
            ans[k++] = bst2[j];
            j++;
        }
    }

    while (i < bst1.size())
    {
        ans[k++] = bst1[i];
        i++;
    }

    while (j < bst2.size())
    {
        ans[k++] = bst2[j];
        j++;
    }
    
    return ans;
}

void convertIntoLL(Node* root,Node* head)
{
    if (root == NULL)
    {
        return;
    }
    
    convertIntoLL(root -> right ,head);

    root -> right = head;

    if(head != NULL)
        head -> left = root;

    head = root;

    convertIntoLL(root -> left, head);
}

Node* mergeLL(Node* head1, Node* head2)
{
    Node* head = NULL;
    Node* tail = NULL;

    while (head1 != NULL && head2 != NULL)
    {
        if (head1 -> data < head2 -> data)
        {
            if (head == NULL)
            {
                head = head1;
                tail = head1;
                head1 = head1 -> right;
            }
            else
            {
                tail -> right = head1;
                head1 -> left = tail;
                tail = head1;
                head1 = head1 -> right;
            }
        }
        else
        {
            if (head == NULL)
            {
                head = head2;
                tail = head2;
                head2 = head2 -> right;
            }
            else
            {
                tail -> right = head2;
                head2->left = tail;
                tail = head2;
                head2 = head2 -> right;
            }
        }
        
    }
    
}

int countNode(Node* root)
{
    if(root == NULL)
        return NULL;

    int cnt = 0;

    while (!root == NULL)
    {
        cnt++;
        root = root -> right;
    }
    return cnt;
}

Node* sortedLLtoBST(Node* &head, int n)
{
    if( n <= 0 || head == NULL)
    {
        return NULL;
    }

    Node* left = sortedLLtoBST(head, n/2);

    Node* root = head;
    root -> left = left;

    head = head -> right;

    root -> right = sortedLLtoBST(head, n - n/2 - 1);
    return root; 
}

Node* mergeBST(Node* root1, Node* root2)
{
    //step1 store inorder
    vector<int> bst1, bst2;
    storeInorder(root1, bst1);
    storeInorder(root2, bst2);

    //ans vector
    vector<int> ans;

    //step 2: merge both sorted arrays
    vector<int> mergeArray = mergeArrays(bst1, bst2, ans);

    int s = 0, e = mergeArray.size() - 1;
    return inorderToBST(s, e, mergeArray); 
}

int main(){

    cout << endl;

    cout << "chal gya me" << endl << endl;
    
    return 0;
}