#include <stdlib.h>  /* exit() y EXIT_FAILURE */
#include <stdio.h>   /* printf(), scanf()     */
#include <stdbool.h> /* Tipo bool             */

#include <assert.h>  /* assert() */

#define SIZE 5
#define CELL_MAX (SIZE * SIZE - 1)

void print_sep(int length) {
    printf("\t ");
    for (int i=0; i < length; i++) printf("................");
    printf("\n");
}

void print_board(char board[SIZE][SIZE]) {
    int cell = 0;

    print_sep(SIZE);
    for (int row = 0; row < SIZE; ++row) {
        for (int column = 0; column < SIZE; ++column) {
            printf("\t | %d: %c ", cell, board[row][column]);
            ++cell;
        }
        printf("\t | \n");
        print_sep(SIZE);
    }
}


char get_winner(char board[SIZE][SIZE]) {
    char winner = '-';

    // winner by row
    for (unsigned int row = 0; row < SIZE; row++) {
        bool all_equal = true;
        for (unsigned int col = 1; col < SIZE; col++) {
            if (board[row][0] != board[row][col]) { 
                all_equal = false;
                break;
            } // execution ends, there is no winner in this row
        }
        if (all_equal && board[row][0] != '-') winner = board[row][0];
    }

    // winner by column
    for (unsigned int col = 0; col < SIZE; col++) {
        bool all_equal = true;
        for (unsigned int row = 0; row < SIZE; row++) {
            if (board[0][col] != board[row][col]) {
                all_equal = false;
                break; // execution ends, there is no winner in this column
            }
        }
        if (all_equal && board[0][col] != '-') winner = board[0][col];
    }

    //  winner by diagonal
    for (unsigned int row = 1, counter = 1; row < SIZE; row++) {
        bool all_equal = true;

        if (board[0][0] != board[row][row]) {
            all_equal = false;
            break; // execution ends, there is no winner 
        }
        else counter++;

        if (all_equal && counter == SIZE) winner = board[0][0];
    }

    // winner by diagonal
    for (unsigned int row = 1, col = SIZE-2, counter = 1; row < SIZE; row++, col--) {
        bool all_equal = true;

        if (board[0][SIZE-1] != board[row][col]) {
            all_equal = false;
            break; // execution ends, there is no winner
        }
        else counter++;

        if (all_equal && counter == SIZE) winner = board[0][SIZE-1];
    }

    return winner;
}


bool has_free_cell(char board[SIZE][SIZE]) {
    bool free_cell = false;

    for (unsigned int row = 0; row < SIZE && !free_cell; row++) {
        for (unsigned int col = 0; col < SIZE && !free_cell; col++) {
            if (board[row][col] == '-') free_cell = true;
        }
    }

    return free_cell;
}


int main(void) {
    printf("TicTacToe [Completo :D]\n");

    char board[SIZE][SIZE];

    for (unsigned int row = 0; row < SIZE; row++) {
        for (unsigned int col = 0; col < SIZE; col++) {
            board[row][col] = '-';
        }
    }

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
            int row = cell / SIZE;
            int colum = cell % SIZE;
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