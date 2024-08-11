#include <stdio.h>
#include "create_board.h"
#include <stdlib.h>
#include <time.h>
#include "solve.h"

int main()
{
    int num_rows = 9;
    int num_cols = 9;
    int board[9][9];

    create_board(board, num_rows, num_cols);
    show_board(board, num_rows, num_cols);
    clock_t start, end;
    start = clock();
    prepareCandidates(board);
    solveSudoku(board, 0, 0);
    end = clock();
    printf("Time taken: %.9f seconds\n", difftime(end, start) / CLOCKS_PER_SEC);
    show_board(board, num_rows, num_cols);
}