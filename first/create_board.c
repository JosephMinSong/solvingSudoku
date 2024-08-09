#include <stdio.h>

void create_board(int board[9][9], int num_rows, int num_cols)
{

    printf("Create the starting board by filling in the board.\n");
    printf("Type the entire row and press enter to finalize the row\n");
    printf("Put '0' where the cell should be empty to be filled by user in the game\n");

    for (int i = 0; i < num_rows; ++i)
    {
        char row[11];
        fgets(row, 11, stdin);
        row[10] = '\0';
        for (int j = 0; j < num_cols; ++j)
        {
            board[i][j] = row[j] - '0';
        }
    }
}

void show_board(int board[9][9], int num_rows, int num_cols)
{

    printf("Here is the board:\n");

    for (int i = 0; i < num_rows; i++)
    {
        for (int j = 0; j < num_cols; j++)
        {
            printf("%d  ", board[i][j]);
        }
        printf("\n");
    }
}