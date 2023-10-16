#include <iostream>
#include <unordered_map>
using namespace std;

class Node
{
    public:
    int data;
    Node* next;
    Node* random;

    Node(int d)
    {
        this -> data = d;
        this -> next = NULL;
        this -> random = NULL;
    }
};

void insertAtTail(Node* head, Node* tail, int d)
{
    Node* temp = new Node(d);

    if(head == NULL)
    {
        head = temp;
        tail = temp;
    }

    tail -> next = temp;
    temp = tail;
}

Node* copyList(Node* head)
{
    Node* cloneHead = NULL;
    Node* cloneTail = NULL;

    Node* temp = head;

    while (temp != NULL)
    {
        insertAtTail(cloneHead, cloneTail, temp -> data);
        temp = temp -> next;
    }
    
    unordered_map<Node*, Node*> oldToNew;

    Node* originalNode = head;
    Node* cloneNode = cloneHead;
    while (originalNode != NULL && cloneNode != NULL)
    {
        oldToNew[originalNode] = cloneNode;
        originalNode = originalNode -> next;
        cloneHead = cloneNode -> next;
    }
    return cloneNode;
}

Node* findMid(Node* head)
{
    Node* slow = head;
    Node* fast = head -> next;

    while (fast != NULL)
    {
        fast = fast -> next;
        if(fast -> next != NULL)
        {
            fast = fast -> next;
        }
        slow = slow -> next;
    }
    return slow;
}

Node* merge(Node* left, Node* right)
{
    if(left == NULL)
        return right;

    if(right == NULL)
        return left;

    Node* ans = new Node(-1);
    Node* temp = ans;

    while (left != NULL && right != NULL)
    {
        if (left -> data < right -> data)
        {
            temp -> next = left;
            temp = left;
            left = left -> next;
        }
        else
        {
            temp -> next = right;
            temp = right;
            right = right -> next;
        }
    }
    while (left != NULL)
    {
        temp -> next = left;
        temp = left;
        left = left -> next;
    }
    
    while (right != NULL)
    { 
        temp -> next = right;
        temp = right;
        right = right -> next;
    }
    
}

Node* mergeSort(Node* head)
{
    if(head == NULL && head -> next == NULL)
    {
        return head;
    }

    Node* mid = findMid(head);

    Node* left = head;
    Node* right = mid -> next;

    left = mergeSort(left);
    right = mergeSort(right);

    Node* result = merge(left, right);

    return result;
}