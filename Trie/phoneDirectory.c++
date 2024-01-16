#include<bits/stdc++.h>
using namespace std;

class TrieNode{
    public:
    char data;
    TrieNode* children[26];
    bool isTerminal;

    TrieNode(char ch)
    {
        data = ch;
        for(int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
        isTerminal = false;
    }
};

class Trie{
    public:
    TrieNode* root;

    Trie() {
        root = new TrieNode('\0');
    }

    void insertUtil(string str, TrieNode* root)
    {
        if(str.length() == 0)
        {
            root->isTerminal = true;
            return;
        }

        int index = str[0];
        TrieNode* temp;

        if(root->children[index] != NULL)
        {
            temp = root->children[index];
        }
        else
        {
            temp = new TrieNode(str[0]);
            root->children[index] = temp;
        }
        insertUtil(str.substr(1), temp);
    }

    void insertWord(string str)
    {
        insertUtil(str, root);
    }

    void printSuggestions(TrieNode* curr, vector<string> temp, string prefix)
    {
        if(curr->isTerminal)
        {
            temp.push_back(prefix);
        }

        for(char i = 'a'; i < 'z'; i++)
        {
            TrieNode* next = curr->children[i-'a'];

            if(next != NULL)
            {
                prefix.push_back(i);
                printSuggestions(next, temp, prefix);
                prefix.pop_back();
            }
        }
    }

    vector<vector<string>> getSuggestions(string word)
    {
        TrieNode* temp = root;
        vector<vector<string> > output;
        string prefix = "";

        for(int ch = 0; ch < word.length(); ch++)
        {
            char lastch = word[ch];
            prefix.push_back(lastch);            

            TrieNode* curr = temp->children[lastch-'a'];
            if(curr == NULL)
            {
                break;
            }
            vector<string> tempv;
            printSuggestions(curr, tempv, prefix);

            output.push_back(tempv);
            tempv.clear();
            temp = curr;
        }
        return output;
    }

    vector<vector<string> > phoneDirectory(vector<string> dial, string word)
    {
        Trie* t = new Trie();

        for(int i = 0; i < dial.size(); i++)
        {
            string str = dial[i];
            t->insertWord(str);
        }

        return getSuggestions(word);
    }
};

int main(){


    return 0;
}