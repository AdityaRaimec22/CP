#include<iostream>
#include<string>
using namespace std;

int reverse(string& str, int i,int j){

    if(i>j)
        return 0;

    else if(str[i]==str[j]){
        i++;
        j--;

        reverse(str,i,j);
    }   
    else{
        return 0;
    }
    return 1;
}

int main(){

    string s = "abhsgufysba";

    // cin >> s;

    int ans = reverse(s,0,s.length() - 1);

    cout << ans << endl;

    return 0;

}