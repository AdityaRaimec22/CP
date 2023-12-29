#include<iostream>
using namespace std;

class NStacks {

    int n;
    int s;
    int *arr;
    int *next;
    int *top;

    int freeSpot;

    public:

    NStacks(int N, int S)
    {
        n = N;
        s = S;
        arr = new int[s];
        next = new int[s];
        top = new int[n];

        freeSpot = 0;

        for (int i = 0; i < s; i++)
        {
            next[i] = i+1;
        }

        next[s-1] = -1;

        for (int i = 0; i < n; i++)
        {
            top[i] = -1;
        }
    }

    bool push(int X, int m) 
    {
        if(freeSpot == -1)
        {
            return false;
        }

        int index = freeSpot;

        arr[index] = X;

        freeSpot = next[index];

        next[index] = top[m-1];

        top[m-1] = index;

        return true;
    }

    int pop(int m)
    {
        if(top[m-1] == -1)
        {
            return -1;
        }

        int index = top[m-1];

        top[m-1] = next[index];

        next[index] = freeSpot;

        freeSpot = index;

        return arr[index];
    }
};

int main()
{

    return 0;
}