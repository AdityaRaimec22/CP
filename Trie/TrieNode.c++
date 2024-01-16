#include<bits/stdc++.h>
using namespace std;

class TrieNode
{
public:
    char data;
    TrieNode* children[26]; // Change this to 26
    bool isTerminal;
    int childCount;

    TrieNode(char ch)
    {
        data = ch;
        childCount = 0;
        for (int i = 0; i < 26; i++) // Change this to 26
        {
            children[i] = NULL;
        }
        isTerminal = false;
    }
};

class longestPrefixTrie
{

};

class Trie
{
public:
    TrieNode* root;

    Trie() {
        root = new TrieNode('\0');
    }

    void insertUtils(TrieNode* root, string word)
    {
        cout << "me nikla gaddi leke" << endl;
        //base case
        if (word.length() == 0)
        {
            root->isTerminal = true;
            return;
        }

        //assumption, will be in CAPS
        int index = word[0] - 'A'; // Change this to 'A'
        TrieNode* child;

        //present
        if (root->children[index] != NULL)
        {
            child = root->children[index];
        }
        else
        {
            //absent
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }
        //Recursion
        insertUtils(child, word.substr(1));
    }

    void insertWord(string word)
    {
        insertUtils(root, word);
    }

    bool searchUtil(TrieNode* root, string word)
    {
        //base case
        if (word.length() == 0)
        {
            return root->isTerminal;
        }

        int index = word[0] - 'A'; // Change this to 'A'
        TrieNode* child;

        //present
        if (root->children[index] != NULL)
        {
            child = root->children[index];
        }
        //absent
        else
        {
            return false;
        }

        //Recursion
        return searchUtil(child, word.substr(1));
    }

    bool search(string word)
    {
        return searchUtil(root, word);
    }

    void printSuggestions(TrieNode* curr, vector<string> &temp, string prefix)
    {
        if (curr->isTerminal)
        {
            temp.push_back(prefix);
        }

        for (char i = 'a'; i <= 'z'; i++)
        {
            TrieNode* next = curr->children[i-'a'];

            if (next != NULL)
            {
                prefix.push_back(i);
                printSuggestions(next, temp, prefix);
                prefix.pop_back();
            }
        }
    }

    vector<vector<string>> getSuggestions(string str)
    {
        TrieNode* prev = root;
        vector<vector<string>> output;
        string prefix = "";

        for (int i = 0; i < str.length(); i++)
        {
            char lastch = str[i];
            prefix.push_back(lastch);

            TrieNode* curr = prev-> children[lastch - 'a'];

            if (curr == NULL)
            {
                break;
            }
            vector<string> temp;
            printSuggestions(curr, temp, prefix);

            output.push_back(temp);
            temp.clear();
            prev = curr;
        }
        return output;
    }

    vector<vector<string>> phoneDirectory(vector<string> &contactList, string &queryString)
    {
        Trie* t = new Trie();

        //insert all contact in Trie
        for(int i = 0; i < contactList.size(); i++)
        {
            string str = contactList[i];
            t->insertWord(str);
        }

        //return ans
        getSuggestions(queryString);
    }
};

int main()
{
    Trie* t = new Trie();

    t->insertWord("ABCD");

    cout << "present or Not: " << t->search("ABCD") << endl;

    cout << "me chal hya bina koi dikkat k" << endl;

    return 0;
}
