#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 4

void displayBoard(char board[SIZE][SIZE]) {
    printf("_________________\n");

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }

    printf("_________________\n");
}

int isValidInput(int row, int col, char value, char board[SIZE][SIZE]) {
    // Periksa baris dan kolom
    for (int i = 0; i < SIZE; i++) {
        if ((board[row][i] == value || board[row][i] == '*') ||
            (board[i][col] == value || board[i][col] == '*')) {
            return 0;
        }
    }

    // Periksa subgrid 2x2
    int startRow = 2 * (row / 2);
    int startCol = 2 * (col / 2);
    for (int i = startRow; i < startRow + 2; i++) {
        for (int j = startCol; j < startCol + 2; j++) {
            if (board[i][j] == value || board[i][j] == '*') {
                return 0;
            }
        }
    }

    return 1;
}

void clearBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void fillRandomNumbers(char board[SIZE][SIZE]) {
    srand(time(NULL));

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (rand() % 2 == 0) {
                char value;
                do {
                    value = '1' + rand() % SIZE;
                } while (!isValidInput(i, j, value, board));
                board[i][j] = value;
            }
        }
    }
}

void playSudoku() {
    char board[SIZE][SIZE];
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            board[i][j] = '*';
        }
    }

    fillRandomNumbers(board);

    printf("Selamat datang di permainan Sudoku 4x4!\n");

    int count = 0;
    char value;

    do {
        displayBoard(board);
        int row, col;

        printf("\nMasukkan Angka pada Baris %d Kolom %d (1-4): ", count / SIZE + 1, count % SIZE + 1);

        if (scanf(" %c", &value) != 1 || !(value >= '1' && value <= '4')) {
            printf("Input tidak valid. Coba lagi.\n");
            clearBuffer();
            continue;
        }

        row = count / SIZE;
        col = count % SIZE;

        if (row < 0 || row >= SIZE || col < 0 || col >= SIZE || !(value >= '1' && value <= '4')) {
            printf("Input tidak valid. Coba lagi.\n");
            clearBuffer();
            continue;
        }

        if (!isValidInput(row, col, value, board)) {
            printf("Input tidak valid. Coba lagi.\n");
            continue;
        }

        board[row][col] = value;
        count++;

    } while (count < SIZE * SIZE);

    displayBoard(board);
    printf("\nPermainan selesai! Terima kasih.\n");
}

int main() {
    playSudoku();

    return 0;
}

