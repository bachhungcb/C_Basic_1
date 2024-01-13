#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    // Kiểm tra số lượng đối số dòng lệnh
    if (argc != 3) {
        printf("Sử dụng: %s <file1> <file2>\n", argv[0]);
        return 1;
    }

    char *file1 = argv[1];
    char *file2 = argv[2];

    FILE *file1_fp = fopen(file1, "a"); // Mở tập tin thứ nhất ở chế độ ghi tiếp
    if (file1_fp == NULL) {
        perror("Lỗi khi mở tập tin thứ nhất");
        return 1;
    }

    FILE *file2_fp = fopen(file2, "r"); // Mở tập tin thứ hai ở chế độ đọc
    if (file2_fp == NULL) {
        perror("Lỗi khi mở tập tin thứ hai");
        fclose(file1_fp);
        return 1;
    }

    char ch;
    while ((ch = fgetc(file2_fp)) != EOF) {
        fputc(ch, file1_fp);
    }

    // Đóng tập tin
    fclose(file1_fp);
    fclose(file2_fp);

    printf("Đã ghép nội dung của '%s' vào cuối '%s'\n", file2, file1);

    return 0;
}
