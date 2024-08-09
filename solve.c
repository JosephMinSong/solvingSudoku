#include <stdio.h>
#include <stdbool.h>

int rowCandidates[9][9];
int colCandidates[9][9];
int squareCandidates[9][9];

// Function to get the grid index for each cell
int getGridIndex(int row, int col)
{
    return ((row / 3) * 3) + (col / 3);
}

// Function to prepare candidate numbers
void prepareCandidates(int board[9][9])
{
    for (int i = 0; i < 9; ++i)
    {
        for (int j = 0; j < 9; ++j)
        {
            int num = board[i][j];
            if (num != 0)
            {
                rowCandidates[i][num] = 1;
                colCandidates[j][num] = 1;
                int square = getGridIndex(i, j);
                squareCandidates[square][num] = 1;
            }
        }
    }
}

// Function to check if the current spot is a valid place to put a number
bool tryCandidateNumbers(int row, int col, int num)
{
    // Check the row
    if (rowCandidates[row][num] == 1)
    {
        return false;
    }

    // Check the column
    if (colCandidates[col][num] == 1)
    {
        return false;
    }

    // Check the 3x3 grid
    int square = getGridIndex(row, col);
    if (squareCandidates[square][num] == 1)
    {
        return false;
    }

    return true;
}

// Need a recursive function for checking candidate numbers
// but need to store the candidate number grids somehow???
// i don't think i gave this a base case so please help idk
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
                    if (tryCandidateNumbers(row, col, num))
                    {
                        board[row][col] = num;
                        rowCandidates[row][num] = 1;
                        colCandidates[col][num] = 1;
                        int square = getGridIndex(row, col);
                        squareCandidates[square][num] = 1;

                        // i don't know if the recursion goes here or out of the for loop but i think it's here
                        // I think recursive step has to be here because if the above step returns true, you move on
                        // and have to continuously solve the board (i.e. move to next cell and keep going)
                        // so placing the recursive step here will continuously try to solve the next cell
                        if (solveSudoku(board))
                        {
                            return true;
                        }

                        rowCandidates[row][num] = 0;
                        colCandidates[col][num] = 0;
                        squareCandidates[square][num] = 0;

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
