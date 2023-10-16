#include <iostream>
using namespace std;

class CircularQueue
{
    int size; 
    int front;
    int rear;
    int *arr;
    public:

    CircularQueue()
    {
        size = 1001;
        arr = new int[size];
        front = -1;
        rear = -1;
    }

    bool enque(int data)
    {
        if((front == 0 && rear == size - 1) || (rear == (front - 1)%(size - 1)))
        {
            cout << "The queue is full" << endl;
            return false;
        }
        else if(front == -1)
        {
            rear = front = 0;
        }
        else if(rear == size - 1 && front != 0)
        {
            rear = 0;
        }
        else
        {
            rear++;
        }
        arr[rear] = data;
        return true;
    }

    bool deque()
    {
        if(front == -1)
        {
            cout << "The queue is empty." << endl;
        }
        int ans = arr[front];
        arr[front] = -1;
        if(front == rear)
        {
            front = rear = -1;
        }
        else if(front == size - 1)
        {
            front = 0;
        }
        else
        {
            front++;
        }
        return ans;
    }
};