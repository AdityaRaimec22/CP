#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Tree{
    public:
    int data;
    Tree* left;
    Tree* right;

    Tree(int d)
    {
        this -> data = d;
        this -> left = NULL;
        this -> right = NULL;
    }
};

class Solution{
    public:
    vector<int> zigzag(Tree* root){
        vector<int> result;
        if(root == NULL)
            return result;

        queue<Tree*> q;
        q.push(root);

        bool leftToRight = true;

        while (!q.empty())
        {
            int size = q.size();
            vector<int> ans(size);

            for (int i = 0; i < size; i++)
            {
                Tree* frontNode = q.front();
                q.pop();

                int index = leftToRight ? i : size - i - 1;
                ans[index] = frontNode -> data;

                if (frontNode -> left)
                {
                    q.push(frontNode -> left);
                }

                if(frontNode -> right)
                {
                    q.push(frontNode -> right);
                }
                
            } 
            leftToRight = !leftToRight;
            for(auto i : ans){
                result.push_back(i);
            }
        }
            return result;
    }
};

bool isIdentical(Tree* r1, Tree* r2)
{
    if(r1 == NULL && r2 == NULL)
    {
        return true;
    }
}

int main(){

    int n;
    cin >> n;

    
    return 0;
}