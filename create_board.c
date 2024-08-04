#include <stdio.h>

int num_rows = 9;
int num_col = 9;
int board[9][9];


void create_board() {
    
    printf("Create the starting board by filling in the board.\n");
    printf("Put '0' where the cell should be empty to be filled by user in the game\n");

    for(int i = 0; i < num_rows; i++) {
        for(int j = 0; j < num_col; j++) {
            scanf("%d", &board[i][j]);
        }
    }
}


void show_board() {
    
    printf("The board you have created looks like this:\n");

    for(int i = 0; i < num_rows; i++) {
        for(int j = 0; j < num_col; j++) {
            printf("%d  ", board[i][j]);
        }
        printf("\n");
    }
}

int main() {
    create_board();
    show_board();
    return 0;
}