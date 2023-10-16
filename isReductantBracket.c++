#include <iostream>
#include <stack>
using namespace std;

bool isReductantBracket(string &s)
{
    stack<char> st;
    for(int i = 0; i < s.length(); i++)
    {
        char ch = s[i];
        if(ch == '(' || ch == '+' || ch == '-' || ch == '*' || ch == '/')
        {
            st.push(ch);
        }
        else
        {
            if(ch == ')')
            {
                bool isReductant = true;
                while(st.top() != '(')
                {
                    char top = st.top();
                    if(top == '+' || top == '-' || top == '*' || top == '/')
                    {
                        isReductant = false;
                    }
                    st.pop();
                }
                if(isReductant == true)
                {
                    return true;
                }
                st.top();
            }
        }
    }
    return false;
}

int main()
{
    string s;

    cin >> s;

    bool value = isReductantBracket(s);

    if(value)
    {
        cout << "The brackets are reductant." << endl;
    }
    else
    {
        cout << "The brackets are not reductant." << endl;
    }

    return 0;
}