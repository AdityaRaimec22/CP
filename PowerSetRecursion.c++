#include <iostream>
#include <vector>
using namespace std;

void solve(vector<string>& ans, string str, string output, int i) {
    //base case
    if(i>=str.length()) {
        // if(output.length()>0)
        ans.push_back(output);
        return ;
        
    }
    
    solve(ans, str, output, i+1);
    output.push_back(str[i]);
    solve(ans, str, output, i+1);
}

vector<string> subsequences(string str){
	vector<string> ans;
    string output = "";
    solve(ans,str,output,0);
    return ans;
}

int main()
{
    string str = "123";
    string str2 = "";
    cout << str.length() << endl;
    cout << str2.length() << endl;
    vector<string> ans;
    ans = subsequences(str);

    for(int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] <<" ";
    }cout << endl;

    return 0;
}