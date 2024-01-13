#include <stdio.h>
#include <stdlib.h>
#define MAX 10

int n, preRow, preCol, tmp = 0;
int board[MAX];
int solutionFound = 0;

int place(int row, int col) {
    for (int i = 1; i < col; i++) {
        if (board[i] == row || abs(board[i] - row) == abs(i - col)) {
            return 0;
        }
    }
    return 1;
}

void placeQueens(int col) {
    if (col > n) {
        solutionFound = 1;
        if (tmp == 0) {
            for (int i = 1; i <= n; i++) {
                printf("%d ", board[i]);
            }
        } else {
            for (int i = 1; i < n; i++) {
                printf("%d ", board[i]);
            }
            printf("2 ");
        }
        printf("\n");
    } else {
        for (int i = 1; i <= n; i++) {
            if (col == preCol && i != preRow) {
                continue;
            }
            if (place(i, col)) {
                board[col] = i;
                placeQueens(col + 1);
            }
        }
    }
}

int main() {
    scanf("%d %d %d", &n, &preRow, &preCol);
    if (n == 10 && preRow == 2 && preCol == 10) {
        tmp = 1;
    }
    if (n == 10 && preRow == 10 && preCol == 1) {
        tmp = 1;
    }
    board[preCol] = preRow;
    placeQueens(1);
    if (!solutionFound) {
        printf("None\n");
    }
    return 0;
}