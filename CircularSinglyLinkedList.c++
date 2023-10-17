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

    ~Node(){
        int value = this -> data;
        if( this -> next != NULL)
        {
            delete next;
            next = NULL;
        }
    }
};

void insertAtNode(Node* &tail, int element, int d){
    if(tail == NULL)
    {
        Node* newNode = new Node(d);
        tail = newNode;
        newNode -> next = newNode;
    }
    else
    {
        Node* curr = tail;

        while (curr -> data != element)
        {
            curr = curr -> next;
        }
        Node* temp = new Node(d);
        temp -> next = curr -> next;
        curr -> next = temp;
    }
}

void print(Node* tail)
{
    Node* temp = tail;
    cout << tail -> next << " ";

    do
    {
        cout << tail -> data << " ";
        tail = tail -> next;
    }while (tail != temp);
    cout << endl;
}

void deleteNode(Node* &tail, int value)
{
    if (tail == NULL)
    {
        cout << " List is empty " << endl;
        return;
    }

    else
    {
        Node* prev = tail;
        Node* curr = prev -> next;

        while (curr -> data != value)
        {
            prev = curr;
            curr = curr -> next;
        }
        prev -> next = curr -> next;
        curr -> next = NULL;
        delete curr;
    }
}

int main(){

    Node* tail = NULL; // Initialize tail to NULL to represent an empty list.
    insertAtNode(tail, 5, 3); // Insert a node with data 10.

    // Now, 'tail' is pointing to the created node forming a circular list.

    print(tail);

    insertAtNode(tail,3,5);

    print(tail); 

    return 0;
}
