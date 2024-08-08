#include <stdio.h>
#include <stdbool.h>

#define N 9

int board[N][N];


//Function to create the board
void create_board() {
    printf("Create the starting board by filling in the board.\n");
    printf("Put '0' where the cell should be empty to be filled by user in the game\n");

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            scanf("%d", &board[i][j]);
        }
    }
}

//Function to print the board after inputting numbers in the board
void show_board() {
    printf("The board you have created looks like this:\n");

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            printf("%d  ", board[i][j]);
        }
        printf("\n");
    }
}

// Function to get the grid index for each cell
int getGridIndex(int row, int col) {
    return ((row/3) * 3) + (col/3);
}

//Function to check if the current spot is a valid place to put a number
//And tries each candidate number. But this might need to be run a few times???
//Num is the number you're looking to place in that spot, so the function
//checks the row for that number, the column, and overall 3x3 grid and if it
//doesn't find it it returns true meaning that number can be placed in this spot
//not sure if need to store the candidate numbers somehow 
bool tryCandidateNumbers(int row, int col, int num) {
    //Check the row
    for (int i = 0; i < N; i++) {
        if (board[row][i] == num) {
            return false;
        }
    }

    //Check the column
    for (int i = 0; i < N; i++) {
        if (board[i][col] == num) {
            return false;
        }
    }

    //Check the 3x3 grid
    int startRow = (row / 3) * 3;
    int startCol = (col / 3) * 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[startRow + i][startCol + j] == num) {
                return false;
            }
        }
    }

    return true;
}


//Need a recursive function for checking candidate numbers
// but need to store the candidate number grids somehow??? 


//Main creates the board and shows the board
// MAIN DOES NOT INCLUDE CHECKING THE GRID RIGHT NOW 
// will need a recursive function
int main() {
    create_board();
    show_board();
    return 0;
}