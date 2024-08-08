#include <stdio.h>
#include <stdbool.h>

#define N 9

int board[N][N];


//Function to create the board
void create_board() {
    printf("Create the starting board by filling in the board.\n");
    printf("Put '0' where the cell should be empty to be filled by user in the game\n");

    for(int row = 0; row < N; row++) {
        for(int col = 0; col < N; col++) {
            scanf("%d", &board[row][col]);
        }
    }
}

//Function to print the board after inputting numbers in the board
void show_board() {
    printf("The board you have created looks like this:\n");

    for(int row = 0; row < N; row++) {
        for(int col = 0; col < N; col++) {
            printf("%d  ", board[row][col]);
        }
        printf("\n");
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
// i don't think i gave this a base case so please help idk 
bool solveSudoku() {
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++){
            //Base case: if the cell is empty (or base case is if the number doesn't lead to a solution??)
            if (board[row][col] == 0) {
                for (int num = 1; num <= 9; num++) {
                    //try placing a number (num is candidate numbers to try)
                    if(tryCandidateNumbers(row, col, num)) {
                        board[row][col] = num;

                        //i don't know if the recursion goes here or out of the for loop but i think it's here
                        //I think recursive step has to be here because if the above step returns true, you move on
                        //and have to continuously solve the board (i.e. move to next cell and keep going)
                        //so placing the recursive step here will continuously try to solve the next cell
                        if (solveSudoku()) {
                            return true;
                        }

                        //if the recursive step returns false that means there's no solution for that cell
                        //so then you backtrack
                        board[row][col] = 0;
                    }
                }

                //Backtrack one more step if all the above return false. I think this only works if there is no
                //solution to the board OR the board is fully solved?
                return false;
            }
        }
    }
    //Last step: no empty cells meaning the board is solved
    return true;
}

//Function to print the solved board
void printSolvedBoard() {
    printf("Here is your solved board!\n");

    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++) {
            printf("%d  ", board[row][col]);
        }
        printf("\n");
    }
}


//Main creates the board and shows the board
// MAIN DOES NOT INCLUDE CHECKING THE GRID RIGHT NOW 
// will need a recursive function
int main() {
    create_board();
    show_board();
    if(solveSudoku()) {
        printSolvedBoard();
    }
    return 0;
}