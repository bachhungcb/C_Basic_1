#include <stdio.h>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void generatePermutations(int arr[], int n, int k, int index) {
    if (index == k) {
        for (int i = 0; i < k; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
        return;
    }

    for (int i = index; i < n; i++) {
        swap(&arr[index], &arr[i]);
        generatePermutations(arr, n, k, index + 1);
        swap(&arr[index], &arr[i]); // Hoàn lại trạng thái ban đầu
    }
}

int main() {
    int n, k;
    printf("Nhập số phần tử (n): ");
    scanf("%d", &n);
    printf("Nhập số phần tử trong chỉnh hợp (k): ");
    scanf("%d", &k);

    if (k > n || k <= 0 || n <= 0) {
        printf("Sai giá trị n hoặc k.\n");
        return 1;
    }

    int arr[n];
    for (int i = 0; i < n; i++) {
        arr[i] = i + 1;
    }

    printf("Cac chinh hop chap %d cua %d phan tu la:\n", k, n);
    generatePermutations(arr, n, k, 0);

    return 0;
}
