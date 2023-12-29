#include <iostream>
using namespace std;

class Queue {
    int *arr;
    int size;
    int qfront;
    int rear;

    public:
    Queue()
    {
        size = 100001;
        arr = new int[size];
        qfront = 0;
        rear = 0;
    }

    bool isEmpty()
    {
        if(rear == qfront)
        {
            return false;
        }
        else
        {
            return true;
        }
    }

    void enqueue(int data)
    {
        if(qfront == rear)
        {
            cout << "queue is full" << endl;
        }
        else
        {
            arr[rear] = data;
            rear++;
        }
    }

    int deque()
    {
        if(qfront == rear)
        {
            return -1;
        }
        else
        {
            int ans = arr[qfront];
            qfront++;
            if(qfront == rear)
            {
                qfront = 0;
                rear = 0;
            }
            return ans;
        }
    }
};

int main()
{

    return 0;
}