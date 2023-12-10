#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MOD 1000000007
#define MAX 1000

unsigned long long M[MAX][MAX];

unsigned long long binomialCoefficient(int k, int n) {
    if (k == 0 || k == n) return M[k][n] = 1;
    else if (M[k][n] == 0) {
        M[k][n] = (binomialCoefficient(k-1, n-1) + binomialCoefficient(k, n-1)) % MOD;
    }
    return M[k][n];
}

int main() {
    int n, k;
    memset(M, 0, sizeof(M));

    scanf("%d %d", &k, &n);

    unsigned long long result = binomialCoefficient(k, n);
    printf("%llu", result);

    return 0;
}
