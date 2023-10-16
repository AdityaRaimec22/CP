#include <iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node* prev;
    Node* next;

    Node(int d)
    {
        this -> data = d;
        this -> next = NULL;
        this -> prev = NULL;
    }
};

void insertAtHead(Node* head, int d)
{
    if(head == NULL)
    {

    }

    Node* newNode = new Node(d);
    newNode -> prev = NULL;
    newNode -> next = head;
    head -> prev = newNode;
    head = newNode;
}

void insertAtPosition(Node* head, int d, int position)
{
    Node* newNode = new Node(d);
    Node* temp = head;

    int cnt = 1;
    while (cnt < position - 1)
    {
        cnt++;
        temp = temp -> next;
    }

    newNode -> next = temp -> next;
    temp -> next -> prev = newNode;
    temp -> next = newNode;
    newNode -> prev = temp;
    
}

void deleteNode(Node* head, int position)
{
    if(position == 1)
    {
        Node* curr = head;
        Node* nextNode = curr -> next;
        curr -> next = NULL;
        nextNode -> prev = NULL;
        head = nextNode;
        delete curr;
    }
}