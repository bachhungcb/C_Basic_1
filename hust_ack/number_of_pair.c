#include <stdio.h>
#include <stdlib.h>

#define MAX 1000000

int hashTable[MAX] = {0};

int main() {
    int n, Q;
    scanf("%d %d", &n, &Q);

    int a[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        hashTable[a[i]]++;
    }

    int count = 0;
    for (int i = 0; i < n; i++) {
        int complement = Q - a[i];
        if (complement >= 0 && complement < MAX) {
            count += hashTable[complement];
            if (complement == a[i]) count--;
        }
    }

    printf("%d\n", count / 2);

    return 0;
}