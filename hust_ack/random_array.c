#include <stdio.h>
#include <stdlib.h>

int steps = 0;
void insert(int* arr, int n, int key) {
    int i = n - 1;
    while (i >= 0 && arr[i] > key) {
        steps++;
        arr[i + 1] = arr[i];
        i = i - 1;
    }
    arr[i + 1] = key;
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[1000];
    int n = 0;
    for(int i = 0; i < 1000; i++) {
        int key = rand() % 100;
        insert(arr, n, key);
        n++;
    }
    printArray(arr, n);
    printf("\nSteps: %d", steps);
    return 0;
}
