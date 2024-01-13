#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) {
    return (*(double *)a - *(double *)b) > 0 ? 1 : -1;
}

int main() {
    int n, i;
    double *arr;
    
    scanf("%d", &n);
    arr = (double*)malloc(n * sizeof(double));
    for (i = 0; i < n; i++) {
        scanf("%lf", &arr[i]);
    }

    qsort(arr, n, sizeof(double), &cmp);

    for (i = n-1; i >= 0; i--) {
        printf("%.2lf\n", arr[i]);
    }

    free(arr);
    return 0;
}

