#include <stdio.h>
#include <stdbool.h>

int rowCandidates[10][10];
int colCandidates[10][10];
int squareCandidates[10][10];

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

bool solveSudoku(int board[9][9], int row, int col)
{
    // First base case
    // If we have reached past the board, we are done
    if (row == 9)
    {
        return true;
    }

    int nextRow = (col == 8 ? row + 1 : row);
    int nextCol = (col == 8 ? 0 : col + 1);

    // Second base case
    // If this square is already filled with a number, we move onto the next
    if (board[row][col] != 0)
    {
        return solveSudoku(board, nextRow, nextCol);
    }

    // Only iterate through candidate numbers because we are manually passing each next row and col to the function
    for (int i = 1; i <= 9; ++i)
    {
        if (tryCandidateNumbers(row, col, i))
        {
            board[row][col] = i;
            rowCandidates[row][i] = 1;
            colCandidates[col][i] = 1;
            int square = getGridIndex(row, col);
            squareCandidates[square][i] = 1;

            if (solveSudoku(board, nextRow, nextCol))
            {
                return true;
            }

            // if the recursive step returns false that means there's no solution for that cell
            // so then you backtrack
            board[row][col] = 0;
            rowCandidates[row][i] = 0;
            colCandidates[col][i] = 0;
            squareCandidates[square][i] = 0;
        }
    }

    return false;
}