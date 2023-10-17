#include<iostream>
using namespace std;

int BinarySearchByRecursion(int *arr, int size,int element){
    int length = sizeof(arr)/sizeof(int);
    if(length>size)
        return 0;

    if(arr[0]==element){
        return 1;
    } else {
        bool foundElement = BinarySearchByRecursion(arr + 1,size - 1,element);
        return foundElement;
    }
}

int main(){
    int n;
    cin >> n;

    int arr[5] = {1,2,3,4,5};

    int ans = BinarySearchByRecursion(arr,5,n);

    if(ans){
        cout<<"the element was found"<<endl;
    } else {
        cout<<"the element was not found"<<endl;
    }

    return 0;
}