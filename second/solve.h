#ifndef SOLVE_H
#define SOLVE_H
#include <stdbool.h>

int getGridIndex(int row, int col);

void prepareCandidates(int board[9][9]);

bool tryCandidateNumbers(int row, int col, int num);

bool solveSudoku(int board[9][9]);

#endif