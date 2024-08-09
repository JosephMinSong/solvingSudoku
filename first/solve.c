#include <stdio.h>
#include <stdbool.h>

int rowCandidates[9][9];
int colCandidates[9][9];
int squareCandidates[9][9];

bool tryCandidateNumbers(int board[9][9], int row, int col, int num)
{
    // Check the row
    for (int i = 0; i < 9; i++)
    {
        if (board[row][i] == num)
        {
            return false;
        }
    }

    // Check the column
    for (int i = 0; i < 9; i++)
    {
        if (board[i][col] == num)
        {
            return false;
        }
    }

    // Check the 3x3 grid
    int startRow = (row / 3) * 3;
    int startCol = (col / 3) * 3;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[startRow + i][startCol + j] == num)
            {
                return false;
            }
        }
    }

    return true;
}

// Need a recursive function for checking candidate numbers
//  but need to store the candidate number grids somehow???
//  i don't think i gave this a base case so please help idk
bool solveSudoku(int board[9][9])
{
    for (int row = 0; row < 9; row++)
    {
        for (int col = 0; col < 9; col++)
        {
            // Base case: if the cell is empty (or base case is if the number doesn't lead to a solution??)
            if (board[row][col] == 0)
            {
                for (int num = 1; num <= 9; num++)
                {
                    // try placing a number (num is candidate numbers to try)
                    if (tryCandidateNumbers(board, row, col, num))
                    {
                        board[row][col] = num;

                        // i don't know if the recursion goes here or out of the for loop but i think it's here
                        // I think recursive step has to be here because if the above step returns true, you move on
                        // and have to continuously solve the board (i.e. move to next cell and keep going)
                        // so placing the recursive step here will continuously try to solve the next cell
                        if (solveSudoku(board))
                        {
                            return true;
                        }

                        // if the recursive step returns false that means there's no solution for that cell
                        // so then you backtrack
                        board[row][col] = 0;
                    }
                }

                // Backtrack one more step if all the above return false. I think this only works if there is no
                // solution to the board OR the board is fully solved?
                return false;
            }
        }
    }
    // Last step: no empty cells meaning the board is solved
    return true;
}