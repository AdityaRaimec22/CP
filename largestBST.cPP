#include<iostream>
#include<climits>
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

class Info{
    public:
    int max;
    int mini;
    bool isBST;
    int size;


};

Info solve(Node* root, int &maxSize)
{
    if(root == NULL)
    {
        return {INT_MIN, INT_MAX, true, 0};
    }

    Info left = solve(root->left, maxSize);
    Info right = solve(root->right, maxSize);

    Info currNode;

    currNode.size = left.size + right.size + 1;
    currNode.max = max(root->data, right.max);
    currNode.mini = min(root->data, left.mini);

    if (left.isBST && right.isBST && (root->data > left.max && root->data < right.mini))
    {
        currNode.isBST = true;
    }
    else
    {
        currNode.isBST = false;
    }
    if (currNode.isBST)
    {
        maxSize = max(maxSize, currNode.size);
    }
    
    return currNode;
}

class Heap {
    public:
    int arr[100];
    int size = 0;

    void insert(int val)
    {
        size = size + 1;
        int index = size;
        arr[index] = val;

        while (index > 1)
        {
            int parent = index/2;

            if (arr[parent] < arr[index])
            {
                swap(arr[parent], arr[index]);
                index = parent;
            }
            else
            {
                return;
            }
        }
    }

    void deleteFromHeap()
    {
        if (size == 0)
        {
            cout << "nothing to delete " << endl;
            return;
        }

        arr[1] == arr[size];
        size--;

        int i = 1;
        while (i<size)
        {
            int leftIndex = 2*i;
            int rightIndex = 2*i + 1;

            if (leftIndex < size && arr[i] < arr[leftIndex])
            {
                swap(arr[i], arr[leftIndex]);
                i = leftIndex;
            }
            else if (rightIndex < size && arr[i] < arr[rightIndex])
            {
                swap(arr[i], arr[rightIndex]);
                i = rightIndex;
            }
            else
            {
                return;
            }
        }
    }

    void print()
    {
        for (int i = 1; i <+ size; i++)
        {
            cout << arr[i] << " ";
        } cout << endl;
        
    }
};

void heapify(int arr[], int n, int i)
{
    int largest = i;
    int left = 2*i;
    int right = 2*i + 1;

    if (left < n && arr[largest] < arr[left])
    {
        largest = left;
    }
    if (right < n && arr[largest] < arr[right])
    {
        largest = right;
    }

    if (largest != i)
    {
        swap(arr[largest] , arr[i]);
        heapify(arr, n, largest);
    }
}

int largestBST(Node* root)
{
    int maxSize = 0;
    Info temp = solve(root, maxSize);
    return maxSize;
}

int main(){


    
    return 0;
}