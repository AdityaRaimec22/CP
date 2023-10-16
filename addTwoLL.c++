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

Node* reverse(Node* head)
{
    Node* curr = head;
    Node* prev = NULL;
    Node* next = NULL;

    while (curr != NULL)
    {
        next = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

void insertAtTail(Node* &head, Node* &tail, int val)
{
    Node* temp = new Node(val);

    if(head == NULL)
    {
        head = temp;
        tail = temp;
        return;
    }
    tail -> next = temp;
    temp = tail;
}

Node* add(Node* first, Node* second)
{
    int carry = 0;

    Node* ansHead = NULL;
    Node* ansTail = NULL;

    while (first != NULL || second != NULL || carry != 0)
    {
        int val1 = 0;
        if(first != NULL)
            val1 = first -> data;

        int val2 = 0;
        if(second != NULL)
            val2 = second -> data;

        int sum = carry + val1 + val2;

        int digit = sum%10;

        insertAtTail(ansHead, ansTail, digit);

        carry = sum/10;

        if(first != NULL)
            first = first -> next;

        if(second != NULL)
            second = second -> next;
    }
    return ansHead;
}

Node* addToLL(Node* first, Node* second)
{
    first = reverse(first);
    second = reverse(second);

    Node* ans = add(first, second);

    ans = reverse(ans);

    return ans;
}