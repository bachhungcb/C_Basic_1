#include <stdio.h>
#include <stdbool.h>

#define MAX_N 1000

bool isPrime(int num) {
    if (num <= 1) {
        return false;
    }
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

void listPrimesRecursive(int n, int current) {
    static bool isPrimeCache[MAX_N] = {false};

    if (current <= n) {
        if (!isPrimeCache[current]) {
            if (isPrime(current)) {
                printf("%d ", current);
            }
            isPrimeCache[current] = true;
        }
        listPrimesRecursive(n, current + 1);
    }
}

int main() {
    int n;
    printf("Nhập vào một số nguyên n: ");
    scanf("%d", &n);
    
    printf("Các số nguyên tố từ 1 đến %d là: ", n);
    listPrimesRecursive(n, 2); // Bắt đầu từ 2 vì 0 và 1 không phải số nguyên tố.

    return 0;
}