#include <iostream>
using namespace std;

class Queue
{
    int qfront;
    int rear;
    int size;
    int *arr;
    public:

    Queue()
    {
        size = 1001;
        qfront = 0;
        rear = 0;
        arr = new int[size];
    }

    void push(int data)
    {
        if(rear ==  size)
            cout << "queue is full "<<endl;

        else
        {
            arr[rear] = data;
            rear++;
        }
    }

    void pop()
    {
        if(rear == qfront)
            cout << "The queue is empty" << endl;

        else
        {
            arr[qfront] = -1;
            qfront++;
            if(qfront==rear){
                qfront = 0;
                rear = 0;
            }
        }
    }

    bool empty()
    {
        if(rear == qfront)
            return true;

        else
        {
            return false;
        }
    }

};

