#include<bits/stdc++.h>
using namespace std;

bool isSafe(int row, int col, int val, vector<vector<int> >& board)
{
    for(int i = 0; i < board.size(); i++)
    {
        if(board[row][i] == val)
        {
            return false;
        }
        if(board[i][col] == val)
        {
            return false;
        }
        if(board[3*(row/3)+i/3][3*(col/3)+i/3] == val)
        {
            return false;
        }
    }
    return true;
}

bool solve(vector<vector<int>> &sudoku)
{
    int size = sudoku[0].size();

    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            if(sudoku[i][j] == 0)
            {
                for(int k = 1; k <= 9; k++)
                {
                    if(isSafe(i, j, k, sudoku))
                    {
                        bool aageSolutionPossible = solve(sudoku);
                        if(aageSolutionPossible)
                        {
                            return true;
                        }
                        else
                        {
                            sudoku[i][j] = 0;
                        }
                    }
                }
                return false;
            }
        }
    }
    return true;
}

void sudokuSolver(vector<vector<int> > &sudoku)
{
    solve(sudoku);
}

int main(){


    return 0;
}