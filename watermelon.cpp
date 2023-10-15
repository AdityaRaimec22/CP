#include<bits/stdc++.h>
using namespace std;

void makeStringsEqual(string s1, string s2, int a, int b)
{
    if(s1.length() != s2.length())
    {
        cout << "NO" << endl;
        return;
    }

    if((a == b) && (s1[a] != s2[b]))
    {
        cout << "NO" << endl;
        return;
    } 
    else if((a == b) && (s1[a] == s2[b]))
    {
        cout << "YES" << endl;
        return;
    }

    if((s1[a] == s2[a]) && (s2[b] == s1[b]) && (s1[a] == s2[b]))
    {
        cout << "YES" << endl;
        return;
    }

    // if

    if((s1[a] == s2[a]) && (s2[b] == s1[b]) && (s1[a] != s2[b]))
    {
        if(((s1[a+1] == s1[b]) && (s2[a+1] == s2[b]) && (s1[a+1] == s2[b])) || ((s1[a] == s1[b-1]) && (s2[a] == s2[b-1]) && (s1[a] == s2[b-1])))
        {
            cout << "YES" << endl;
            return;
        } else {
            makeStringsEqual(s1, s2, ++a, --b);
        }
    }
    else if((s1[a] != s2[a]) && (s2[b] == s1[b]))
    {
        makeStringsEqual(s1, s2, a, --b);
    }
    else if((s1[a] == s2[a]) && (s2[b] != s1[b]))
    {
        makeStringsEqual(s1, s2, a++, b);
    }
}

int main(){

    int t;
    cin >> t;

    while (t--)
    {
        string s1, s2;
        cin>> s1 >> s2;
        int a = 0;
        int b = s1.length() - 1;
        makeStringsEqual(s1, s2, a, b);
    }

    return 0;
}