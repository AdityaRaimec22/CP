#include<bits/stdc++.h>
using namespace std;

class TrieNode{
    public:
    char data;
    TrieNode* children[26];
    bool isTerminal;
    int childCount;

    TrieNode(char ch)
    {
        data = ch;
        isTerminal = false;
        for(int i = 0; i < 26; i++)
        {
            children[i] == NULL;
        }
        childCount = 0;
    }
};

class Trie{
    public:
    TrieNode* root;
    void insertUtil(TrieNode* root, string word)
    {
        if(word.length() == 0)
        {
            root->isTerminal = true;
            return;
        }

        int index = word[0] - 'A';
        TrieNode* child;

        if(root->children[index] != NULL)
        {
            child = root->children[index];
        }
        else
        {
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }

        insertUtil(child, word.substr(1));
    }

    void insertWord(string word)
    {
        insertUtil(root, word);
    }

    bool searchUtil(TrieNode* root, string word)
    {
        if(word.length() == 0)
        {
            return root->isTerminal;
        }

        int index = word[0] - 'A';
        TrieNode* child;

        if(root->children[index] != NULL)
        {
            child = root->children[index];
        }
        else
        {
            return false;
        }

        return searchUtil(child, word.substr(1));
    }

    bool searchWord(string word)
    {
        return searchUtil(root, word);
    }
};

string longestCommonPrefix(vector<string> &arr, int n)
{
    string ans = "";
    for(int i = 0; i < arr[0].length(); i++)
    {
        char ch = arr[0][i];

        bool match = true;

        for(int j = 1; j<n; j++)
        {
            //not match
            if(arr[j].size() < i || ch != arr[j][i])
            {
                match = false;
                break;
            }
        }
        if(!match)
        {
            break;
        }
        else
        {
            ans.push_back(ch);
        }
    }
    return ans;
}

int main(){


    return 0;
} 