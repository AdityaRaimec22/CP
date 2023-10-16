#include <iostream>
using namespace std;

int fiboncci(int n)
{
    if(n==0)
        return 0;

    if(n==1)
        return 1;

    return fiboncci(n-2) + fiboncci(n-1);
}

void sayDigit(int n, string arr[]) {

    //base case
    if(n == 0)
        return ;

    //processing 
    int digit = n % 10;
    n = n / 10;
    

    //recursive call
    sayDigit(n, arr);

    cout << arr[digit] << " ";

}

int BinarySearch(int *arr, int s, int e, int k)
{
    int mid = s + (e-s)/2;

    if(s>e)
        return -1;

    if (arr[mid] == k)
        return mid;

    if(arr[mid] < k)
        BinarySearch(arr, mid+1, e, k);
    else{
        BinarySearch(arr, s, mid-1, k);
    }
}

int main()
{
     string arr[10] = {"zero", "one", "two", "three",
                         "four", "five", "six"
                        , "seven", "eight", "nine"};
    int n;
    cin >> n;

    cout << endl << endl << endl ;
    sayDigit(n, arr);
    cout << endl << endl << endl ;

}