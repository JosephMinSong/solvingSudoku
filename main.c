#include <stdio.h>
#include "create_board.h"
#include "solve.h"

int main()
{
    int num_rows = 9;
    int num_cols = 9;
    int board[9][9];

    create_board(board, num_rows, num_cols);
    show_board(board, num_rows, num_cols);
    prepareCandidates(board);
    solveSudoku(board);
    show_board(board, num_rows, num_cols);
}