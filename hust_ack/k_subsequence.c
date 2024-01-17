#include <stdio.h>

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    int a[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    int count = 0;
    int sum = 0;
    for (int i = 0; i < k; i++) {
        sum += a[i];
    }
    if (sum % 2 == 0) {
        count++;
    }

    for (int i = k; i < n; i++) {
        sum = sum - a[i - k] + a[i];
        if (sum % 2 == 0) {
            count++;
        }
    }

    printf("%d\n", count);

    return 0;
}