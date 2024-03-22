#include <stdlib.h>  /* exit() y EXIT_FAILURE */
#include <stdio.h>   /* printf(), scanf()     */
#include <stdbool.h> /* Tipo bool             */

#include <assert.h>  /* assert() */

#define CELL_MAX (3 * 3 - 1)

void print_sep(int length) {
    printf("\t ");
    for (int i=0; i < length; i++) printf("................");
    printf("\n");
}

void print_board(char board[3][3]) {
    int cell = 0;

    print_sep(3);
    for (int row = 0; row < 3; ++row) {
        for (int column = 0; column < 3; ++column) {
            printf("\t | %d: %c ", cell, board[row][column]);
            ++cell;
        }
        printf("\t | \n");
        print_sep(3);
    }
}


char get_winner(char board[3][3]) {
    char winner = '-';

    /* winner by row
        |x|x|x|     | | | |     | | | |
        | | | |     |x|x|x|     | | | |
        | | | |     | | | |     |x|x|x|
    */
    for (unsigned int row = 0; row < 3 && winner == '-'; row++) {
        if (board[row][0] == board[row][1] && board[row][0] == board[row][2]) return board[row][0];
    }

    /*  winner by column
        |x| | |     | |x| |     | | |x|
        |x| | |     | |x| |     | | |x|
        |x| | |     | |x| |     | | |x|
    */
    for (unsigned int col = 0; col < 3 && winner == '-'; col++) {
        if (board[0][col] == board[1][col] && board[0][col] == board[2][col]) return board[0][col];
    }
    

    /*  winner by diagonal
        |x| | |     | | |x|
        | |x| |     | |x| |
        | | |x|     |x| | |
    */
    if (board[0][0] == board[1][1] && board[0][0] == board[2][2]) return board[0][0];
    else if (board[1][1] == board[0][2] && board[1][1] == board[2][0]) return board[1][1];

    return winner;
}


bool has_free_cell(char board[3][3]) {
    bool free_cell = false;

    for (unsigned int row = 0; row < 3 && !free_cell; row++) {
        for (unsigned int col = 0; col < 3 && !free_cell; col++) {
            if (board[row][col] == '-') free_cell = true;
        }
    }

    return free_cell;
}


int main(void) {
    printf("TicTacToe [Completo :D]\n");

    char board[3][3] = {
        { '-', '-', '-' },
        { '-', '-', '-' },
        { '-', '-', '-' }
    };

    char turn = 'X';
    char winner = '-';
    int cell = 0;
    while (winner == '-' && has_free_cell(board)) {
        print_board(board);
        printf("\nTurno %c - Elija posición (número del 0 al %d): ", turn, CELL_MAX);
        int scanf_result = scanf("%d", &cell);
        if (scanf_result <= 0) {
            printf("Error al leer un número desde teclado\n");
            exit(EXIT_FAILURE);
        }
        if (cell >= 0 && cell <= CELL_MAX) {
            int row = cell / 3;
            int colum = cell % 3;
            if (board[row][colum] == '-') {
                board[row][colum] = turn;
                turn = turn == 'X' ? 'O' : 'X';
                winner = get_winner(board);
            } else {
                printf("\nCelda ocupada!\n");
            }
        } else {
            printf("\nCelda inválida!\n");
        }
    }
    print_board(board);
    if (winner == '-') {
        printf("Empate!\n");
    } else {
        printf("Ganó %c\n", winner);
    }
    return 0;
}