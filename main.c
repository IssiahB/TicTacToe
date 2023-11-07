#include <stdio.h>
#include <ctype.h>

#define BOARD_SIZE 3
#define X_PLAYER 'X'
#define Y_PLAYER 'Y'
#define NON_PLAYER ' '

typedef enum { true, false } bool;

typedef struct {
    bool occupied;
    char player;
} square;

square board[BOARD_SIZE][BOARD_SIZE];

void initializeBoard(void);
void printBoard(void);

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("Usage: ./tictactoe ['x' or 'y']\n");
        return 1;
    }

    initializeBoard();
    printBoard();
}

void initializeBoard(void) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j].occupied = false;
            board[i][j].player = NON_PLAYER;
        }
    }
}

void printBoard(void) {
    printf("\n Game Board\n");

    for (int col = 0; col < BOARD_SIZE; col++) {
        for (int row = 0; row < BOARD_SIZE; row++) {
            if (row == 0) {
                printf(" %c ", board[col][row].player);
            } else {
                printf("| %c ", board[col][row].player);
            }
        }

        printf("\n");
    }
}