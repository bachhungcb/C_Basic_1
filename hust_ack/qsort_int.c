#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int main() {
    int n, i;
    int arr[n];

    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    qsort(arr, n, sizeof(int), cmp);

    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}

