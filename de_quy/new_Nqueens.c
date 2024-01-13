#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int n;
int** board;
int** visited;

int queens_placed = 0;

int is_safe(int row, int col) {
    // Check row
    for (int i = 0; i < row; i++) {
        if (board[i][col] == 1) {
            return 0;
        }
    }

    // Check column
    for (int i = 0; i < col; i++) {
        if (board[row][i] == 1) {
            return 0;
        }
    }

    // Check diagonal
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 1) {
            return 0;
        }
    }

    // Check anti-diagonal
    for (int i = row, j = col; i >= 0 && j < n; i--, j++) {
        if (board[i][j] == 1) {
            return 0;
        }
    }

    return 1;
}

void print_board() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
    printf("Queens placed: %d\n", queens_placed);
}

void solve_n_queen(int row) {
    if (row == n) {
        print_board();  // Print the board before incrementing queens_placed
        queens_placed++;
        return;
    }

    for (int col = 0; col < n; col++) {
        if (is_safe(row, col)) {
            board[row][col] = 1;
            visited[row][col] = 1;

            solve_n_queen(row + 1);

            board[row][col] = 0;
            visited[row][col] = 0;
        }
    }
}


int main() {
    printf("Enter the size of the board: ");
    scanf("%d", &n);

    board = (int**)malloc(n * sizeof(int*));
    visited = (int**)malloc(n * sizeof(int*));

    if (board == NULL || visited == NULL) {
        printf("Memory allocation failed\n");
        return 1; // Return an error code
    }

    for (int i = 0; i < n; i++) {
        board[i] = (int*)malloc(n * sizeof(int));
        visited[i] = (int*)malloc(n * sizeof(int));

        if (board[i] == NULL || visited[i] == NULL) {
            printf("Memory allocation failed\n");
            return 1; // Return an error code
        }
    }

    memset(board, 0, n * sizeof(int));
    memset(visited, 0, n * sizeof(int));

    solve_n_queen(0);

    // Free allocated memory
    for (int i = 0; i < n; i++) {
        free(board[i]);
        free(visited[i]);
    }
    free(board);
    free(visited);

    return 0;
}
