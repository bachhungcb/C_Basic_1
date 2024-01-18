#include <stdio.h>
#include <stdlib.h>

int maxArea(int* histogram, int n) {
    int* stack = (int*)malloc(n * sizeof(int));
    int top = -1;
    int maxArea = 0;
    int areaWithTop;
    int i = 0;

    while (i < n) {
        if (top == -1 || histogram[stack[top]] <= histogram[i])
            stack[++top] = i++;
        else {
            int tp = stack[top--];
            areaWithTop = histogram[tp] * (top == -1 ? i : i - stack[top] - 1);

            if (maxArea < areaWithTop)
                maxArea = areaWithTop;
        }
    }

    while (top != -1) {
        int tp = stack[top--];
        areaWithTop = histogram[tp] * (top == -1 ? i : i - stack[top] - 1);

        if (maxArea < areaWithTop)
            maxArea = areaWithTop;
    }

    free(stack);
    return maxArea;
}

int main() {
    int n;
    scanf("%d", &n);
    int* histogram = (int*)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++)
        scanf("%d", &histogram[i]);

    printf("%d\n", maxArea(histogram, n));
    free(histogram);
    return 0;
}