#include <stdio.h>

int main() {
    int n, b;
    scanf("%d %d", &n, &b);

    int a[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i] + a[j] == b) {
                count++;
            }
        }
    }

    printf("%d\n", count);

    return 0;
}
