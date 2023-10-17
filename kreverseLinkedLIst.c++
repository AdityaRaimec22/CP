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
};

Node* kReverse(Node* head, int k)
{
    if(head == NULL)
    {
        return NULL;
    }

    Node* next = NULL;
    Node* curr = head;
    Node* prev =NULL;
    int cnt = 0;

    while (curr != NULL && cnt < k)
    {
        next = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = next;
        cnt++;
    }

    if( next != NULL)
    {
        head -> next = kReverse(next, k);
    }

    return prev;
    
}

bool detectLoop(Node* head)
{
    if(head == NULL)
    {
        return false;
    }

    map<Node*,bool> visited;

    Node* temp = head;

    while (temp != NULL)
    {
        if(visited[temp] == true)
        {
            return 1;
        }

        visited[temp] = true;
        temp = temp -> next;
    }
    return false;
     
}

Node* floydDetectLoop(Node* head)
{
    if(head == NULL)
    {
        return NULL;
    }

    Node* slow = head;
    Node* fast = head;

    while (slow != NULL && fast != NULL)
    {
        fast = fast -> next;
        if (fast != NULL)
        {
            fast = fast -> next;
        }
        slow = slow -> next;

        if( fast == slow)
        {
            return slow;
        }
    }
    return NULL;
}

Node* getStartingNode(Node* head)
{
    if(head == NULL)
    {
        return NULL;
    }

    Node* intersection = floydDetectLoop(head);
    Node* slow = head;

    while (slow != intersection)
    {
        slow = slow -> next;
        intersection = intersection -> next;
    }
    return slow;
}

void removeLoop(Node* head)
{
    if(head == NULL)
    {
        return;
    }

    Node* startOfLoop = getStartingNode(head);
    Node* temp = head;

    while (temp -> next != startOfLoop)
    {
        temp = temp ->next;
    }
    temp -> next = NULL;
}

Node* removeDuplicate(Node* head)
{
    Node* curr = head;

    while (curr != NULL)
    {
        if((curr -> next != NULL) && (curr -> data = curr -> next -> data))
        {
            Node* next_next = curr -> next -> next;
            Node* nodeToDelete = curr -> next;
            delete(nodeToDelete);
            curr -> next = next_next;
        }
        else
        {
            curr = curr -> next;
        }
    }
    return head;
}

Node* sortedLinkedList(Node* head)
{
    int zeroCount = 0;
    int oneCount = 0;
    int twoCount = 0;

    Node* temp = head;
    while (temp != NULL)
    {
        if(temp -> data == 0)
        {
            zeroCount++;
        }
        else if(temp -> data == 1)
        {
            oneCount++;
        }
        else if(temp -> data == 2)
        {
            twoCount++;
        }
        temp = temp -> next;
    }

    temp = head;
    while (temp != NULL)
    {
        if(zeroCount != 0)
        {
            temp -> data = 0;
            zeroCount--;
        }
        else if(oneCount != 1)
        {
            temp -> data = 1;
            oneCount;
        }
        else if(twoCount != 2)
        {
            temp -> data = 2;
            twoCount;
        }
        temp = temp -> next;
    }
    return head;
}

void insertAtTail(Node* tail, Node* curr)
{
    tail -> next = curr;
    tail = curr;
}

Node* sortLinkedList(Node* head)
{
    Node* zeroHead = new Node(-1);
    Node* zeroTail = zeroHead;
    Node* oneHead = new Node(-1);
    Node* oneTail = oneHead;
    Node* twoHead = new Node(-1);
    Node* twoTail = twoHead;

    Node* curr = head;

    while (curr != NULL)
    {
        int value = curr -> data;

        if(value == 0)
        {
            insertAtTail(zeroTail, curr);
        }
        else if(value == 1)
        {
            insertAtTail(oneTail, curr);
        }
        else if(value == 2)
        {
            insertAtTail(twoTail, curr);
        }
        curr = curr -> next;
    }

    if(oneHead -> next != NULL)
    {
        zeroTail -> next = oneHead -> next;
    }
    else
    {
        zeroTail -> next = twoHead -> next;
    }

    oneTail -> next = twoHead -> next;
    twoTail -> next = NULL;

    head = zeroHead -> next;

    delete zeroHead;
    delete oneHead;
    delete twoHead;

    return head;
    
}

bool isCircular(Node* head)
{
    if( head == NULL)
    {
        return true;
    }

    Node* temp = head -> next;
    while (temp != NULL && temp != head)
    {
        temp = temp -> next;
    }
    
    if(temp == head)
    {
        return true;
    }

    return false;
}

int main()
{

    return 0;
}