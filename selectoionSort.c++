// #include <iostream>
// #include <vector>
// using namespace std;

// void selectionSort(vector<int> &arr, int n)
// {
//     for(int i = 0; i < n - 1; i++)
//     {
//         int minIndex = i;
//         for(int j = i + 1; j < n; j++)
//         {
//             if(arr[j] < arr[minIndex])
//             {
//                 minIndex = j;
//             }
//         }
//         swap(arr[minIndex], arr[i]);
//     }
// }

// int main()
// {
//     vector<int> arr;
//     arr.push_back(5);
//     arr.push_back(11);
//     arr.push_back(1);
//     arr.push_back(6);

//     selectionSort(arr, 4);

//     for (int i = 0; i < 4; i++)
//     {
//         cout << arr[i] << " ";
//     }
    
// }

#include<iostream>
using namespace std;

int power(int a, int b) {

    cout <<"function executed"<<endl;
    //base case
    if( b == 0 )
        return 1;

    if(b == 1)
        return a;

    //RECURSIVE CALL
    int ans = power(a, b/2);

    //if b is even
    if(b%2 == 0) {
        return ans * ans;
    }
    else {
        //if b is odd
        return a * ans * ans;
    }
}

int main() {

    int a,b;
    cin >> a >> b;
    cout << endl;
    int ans = power(a,b);

    cout << "Answer is " << ans << endl;

    return 0;
}