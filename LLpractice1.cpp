#include <iostream>
#include <map>
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

    ~Node()
    {
        int value = this -> data;

        if(this -> next != NULL)
        {
            delete next;
            this -> next = NULL;
        }
    }

    void insertAtHead(Node* head, int d)
    {
        Node* node1 = new Node(d);
        node1 -> next = head;
        head = node1;
    }

    void insertAtTail(Node* tail, int d)
    {
        Node* node1 = new Node(d);
        tail -> next = node1;
        tail = node1;
    }

    void insertAtPosition(Node* head, Node* tail, int d, int position)
    {
        Node* nodeToInsert = new Node(d);
        Node* temp = head;

        if(position == 1)
        {
            insertAtHead(head, d);
            return;
        }

        int cnt = 1;

        while(cnt < position - 1)
        {
            temp = temp -> next;
            cnt++;
        }

        if(temp -> next == NULL)
        {
            insertAtTail(tail, d);
            return;
        }

        nodeToInsert -> next = temp -> next;
        temp -> next = nodeToInsert;
        
    }

    void deleteNode(Node* head, Node* tail, int position)
    {
        if(position == 1)
        {
            Node* temp = head;
            head = head -> next;
            head -> next = NULL;
            delete temp;
        }

        Node* curr = head;
        Node* prev = NULL;

        int cnt = 1;
        while(cnt < position)
        {
            prev = curr;
            curr = curr -> next;
            cnt++;
        }

        prev -> next = curr -> next;
        curr -> next = NULL;
        delete curr;
    }

    bool isCircular(Node* head)
    {
        // Node* temp = head;
        Node* curr = head -> next;

        while (curr != NULL && curr != head)
        {
            curr = curr -> next;
        }
        
        if(curr == head)
        {
            return true;
        }

        return false;
    }

    bool floydDetectLoop(Node* head)
    {
        if(head == NULL)
            return NULL;

        Node* slow = head;
        Node* fast = head;

        while (slow -> next != NULL)
        {
            slow = slow -> next;
            fast = fast -> next;
            if(fast -> next != NULL)
            {
                fast = fast -> next;
            }
        }

        if(slow == fast)
        {
            return true;
        }

        return false;
        
    }

    void insertNode(Node* &tail, int element, int d)
    {
        if(tail == NULL)
        {
            Node* newNode = new Node(d);
            tail = newNode;
            newNode -> next = newNode;
        }

        Node* curr = tail;

        while(curr -> data != element)
        {
            curr = curr -> next;
        }

        Node* temp = new Node(d);
        temp -> next = curr -> next;
        curr -> next = temp;
    }

    void deleteNode(Node* &tail, int element)
    {
        if(tail == NULL)
        {
            cout << "The List is empty." << endl;
            return;
        }

        Node* curr = tail;
        Node* nextNode = tail -> next;

        while (tail -> data != element)
        {
            curr = curr -> next;
            nextNode = nextNode -> next;
        }
        curr -> next = nextNode -> next;

        if(curr = nextNode)
        {
            tail = NULL;
        }

        else if(tail == curr)
        {
            tail = curr;
        }

        curr -> next = NULL;
        delete curr;
    }

    bool detectLoop(Node* tail)
    {
        if(tail == NULL)
        {
            return false;
        }

        map<Node*, bool> visited;
        Node* temp = tail;

        while (temp != NULL)
        {
            if(visited[temp] == true)
            {
                return true;
            }

            visited[temp] = true;
            temp = temp -> next;
        }
        return false;
    }

    Node* reverseLL(Node* head)
    {
        if(head ==  NULL || head -> next == NULL)
        {
            return;
        }

        Node* prev = NULL;
        Node* curr = head;
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

    void reverse(Node* &head, Node* curr, Node* prev)
    {
        if(curr == NULL)
        {
            head = prev;
            return;
        }

        reverse(head, curr -> next, curr);
        curr -> next = prev;
    }
};

