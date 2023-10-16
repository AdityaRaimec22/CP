#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int d)
    {
        this -> data = d;
        this -> next = NULL;
    }
};

Node* getMiddle(Node* head){

    if(head == NULL || head -> next == NULL)
    {
        return NULL;
    }

    if(head -> next -> next == NULL)
    {
        return head -> next;
    }
    
    Node* slow = head;
    Node* fast = head -> next;

    while (fast != NULL)
    {
        fast = fast -> next;
        if( fast != NULL)
        {
            fast = fast -> next;
        }
        slow = slow -> next;
    }
    return slow;
}