#include <iostream>
using namespace std;

class Node{
    public:
    int data; 
    Node* next;

    Node(int d){
        this -> data = d;
        this -> next = NULL;
    }

};

void reverse(Node *&head,Node* curr, Node* prev ){
    if( curr == NULL)
    {
        head = prev;
        return;
    }

    reverse(head, curr->next,curr);
    curr -> next = prev;
}

Node* reverse1(Node* head)
{
    if(head == NULL || head->next || NULL)
    {
        return head;
    }

    Node* chotaHead = reverse1( head -> next);

    head -> next -> next = head;
    head -> next = NULL;
    
    return chotaHead;
}

int main(){

    Node* head = new Node(10);

    Node* curr = head;
    Node* prev = NULL;

    reverse(head, curr, prev);

}