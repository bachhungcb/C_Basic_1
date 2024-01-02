#include <stdio.h>
#include <stdlib.h>

int n, x[100];
int row, col;

void print_solution() {
    for (int j = 1; j <= n; j++) {
        printf("%d ", x[j]);
    }
    printf("\n");
}

int check(int v, int k) {
    for (int i = 1; i <= k - 1; i++) {
        if (x[i] == v) return 0;
        if (x[i] + i == v + k) return 0;
        if (x[i] - i == v - k) return 0;
    }
    return 1;
}

void TRY(int k) {
    for (int v = 1; v <= n; v++) {
        if (check(v, k)){
                x[k] = v;
            if (k == n) {
                print_solution();
            } else TRY(k + 1);
        }
    }
}

int main() {
    scanf("%d %d %d", &n, &row, &col); 
    x[row] = col;
    
    TRY(1);
    printf("\n%d", x[row]);
    return 0;
}
