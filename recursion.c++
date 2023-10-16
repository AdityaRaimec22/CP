#include<iostream>
using namespace std;

bool isSorted(int *arr, int size){
    if(size==0 || size==1){
        return true;
    }

    if(arr[0]>arr[1]){
        return false;
    } else {
        bool remainigPart = isSorted(arr + 1, size - 1);
        return remainigPart;
    }
}

int main(){
    int arr[5] = {1,2,30,4,5};
    int size = 5;

    int ans = isSorted(arr,size);

    if(ans){
        cout<<"the array is sorted"<<endl;
    } else {
        cout<<"the array is unsorted"<<endl;
    }

    return 0;
}
