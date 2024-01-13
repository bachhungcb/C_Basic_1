#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LINES 10000
#define MAX_LENGTH 101

// Hàm so sánh tùy chỉnh cho qsort
int compare(const void *a, const void *b) {
    return strcmp((char *)a, (char *)b);
}

int main() {
    int n, i;
    char lines[MAX_LINES][MAX_LENGTH];

    scanf("%d", &n);
    getchar();  // Loại bỏ ký tự xuống dòng

    for(i = 0; i < n; i++) {
        fgets(lines[i], MAX_LENGTH, stdin);
        lines[i][strcspn(lines[i], "\n")] = 0;  // Loại bỏ ký tự xuống dòng
    }

    // Sắp xếp các dòng theo thứ tự bảng mã ASCII
    qsort(lines, n, MAX_LENGTH, compare);

    for(i = 0; i < n; i++) {
        printf("%s\n", lines[i]);
    }

    return 0;
}
