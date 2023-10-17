#include <iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node* next;

    Node(int d)
    {
        this -> data = d;
        this -> next = NULL;
    }
};

void insertAtHead(Node* &head, int d)
{
    Node* newNode = new Node(d);
    newNode -> next = head;
    newNode = head;
}

void insertAtTail(Node* &tail, int d)
{
    Node* nodeToInsert = new Node(d);
    tail -> next = nodeToInsert;
    nodeToInsert = tail;
}

void print(Node* head)
{
    Node* temp = head;
    if(head == NULL)
    {
        cout << "The list is empty." << endl;
        return;
    }

    while (temp != NULL)
    {
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout << endl;
}

void insertAtPosition(Node* head, Node* tail, int position, int d)
{
    if(position == 1)
    {
        insertAtHead(head, d);
        return;
    }

    int cnt = 1;
    Node* temp = head;
    while(temp != NULL)
    {
        cnt++;
        temp = temp -> next;
    }

    if(temp -> next == NULL)
    {
        insertAtTail(tail, d);
        return;
    }

    Node* nodeToInsert = new Node(d);
    nodeToInsert -> next = temp -> next;
    temp -> next = nodeToInsert;
}

void deleteNode(int position, Node* &head)
{
    if(position == 1)
    {
        Node* temp = head;
        head = head -> next;
        temp -> next = NULL;
        delete temp;
    }
    else
    {
        Node* curr = head;
        Node* prev = NULL;

        int cnt = 1;
        while (curr != NULL)
        {
            curr = curr -> next;
            cnt++;
        }
        prev -> next = curr -> next;
        curr -> next = NULL;
        delete curr;
    }
}

Node* kReverse(Node* head, int k)
{
    if(head == NULL)
    {
        return NULL;
    }

    Node* prev = NULL;
    Node* curr = head;
    Node* next = NULL;
    int cnt = 0;

    while (curr != NULL && cnt < k)
    {
        next = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = next;
        cnt++;
    }

    if(next != NULL)
    {
        head -> next = kReverse(next, k);
    }
    return prev;
    
}