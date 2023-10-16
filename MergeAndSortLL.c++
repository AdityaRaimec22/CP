#include <iostream>
#include <vector>
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

bool checkPalindrome(vector<int> arr)
{
    int n = arr.size();
    int s = 0;
    int e = n - 1;

    while (s <= e)
    {
        if(arr[s] != arr[e])
        {
            return 0;
        }
        s++;
        e--;
    }
    return 1;
    
}

Node* getMiddle(Node* head)
{
    Node* slow = head;
    Node* fast = head -> next;

    while (fast != NULL && fast -> next != NULL)
    {
        fast = fast -> next -> next;
        slow = slow -> next;
    }
    return slow;
}

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

bool IsPalindrome(Node* head)
{
    if(head -> next == NULL)
        return true;

    Node* middle = getMiddle(head);

    Node* temp = middle -> next;
    middle -> next = reverse(head);

    Node* head1 = head;
    Node* head2 = middle -> next;

    while (head2 != NULL)
    {
        if(head1 -> data != head2 -> data)
        {
            return 0;
        }
        head1 = head1 -> next;
        head2 = head2 -> next;
    }
    return head;
}

bool isPalindrome(Node* head)
{
    vector<int> arr;
    Node* temp = head;

    while (temp != NULL)
    {
        arr.push_back(temp -> data);
        temp = temp -> next;
    }
    return checkPalindrome(arr);
}

void solve(Node* first, Node* second)
{
    Node* curr1 = first;
    Node* next1 = curr1 -> next;
    Node* curr2 = second;
    Node* next2 = curr2 -> next;

    while (next1 != NULL && curr2 != NULL)
    {
        if ((curr2 -> data >= curr1 -> data) && (curr2 -> data <= next1 -> data))
        {
            curr1 -> next = curr2;
            next2 = curr2 -> next;
            curr2 -> next = next1;

            curr1 = curr2;
            curr2 = next2;
        }
        
    }
    
}