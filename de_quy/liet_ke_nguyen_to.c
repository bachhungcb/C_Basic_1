#include <stdio.h>
#include <stdbool.h>

bool isPrime(int num, int divisor) {
    if (divisor <= 1) {
        return true;
    }
    if (num % divisor == 0) {
        return false;
    }
    return isPrime(num, divisor - 1);
}

void listPrimes(int n, int current) {
    if (current <= n) {
        if (isPrime(current, current - 1)) {
            printf("%d ", current);
        }
        listPrimes(n, current + 1);
    }
}

int main() {
    int n;
    printf("Nhập vào một số nguyên n: ");
    scanf("%d", &n);
    
    printf("Các số nguyên tố từ 1 đến %d là: ", n);
    listPrimes(n, 2); // Bắt đầu từ 2 vì 0 và 1 không phải số nguyên tố.

    return 0;
}