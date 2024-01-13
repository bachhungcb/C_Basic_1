#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    // Kiểm tra số lượng đối số dòng lệnh
    if (argc != 3) {
        printf("Sử dụng: %s <tập_tin_nguồn> <tập_tin_đích>\n", argv[0]);
        return 1;
    }

    char *source_file = argv[1];
    char *destination_file = argv[2];

    FILE *source_fp = fopen(source_file, "r");
    if (source_fp == NULL) {
        perror("Lỗi khi mở tập tin nguồn");
        return 1;
    }

    FILE *destination_fp = fopen(destination_file, "w");
    if (destination_fp == NULL) {
        perror("Lỗi khi mở tập tin đích");
        fclose(source_fp);
        return 1;
    }

    char ch;
    while ((ch = fgetc(source_fp)) != EOF) {
        fputc(ch, destination_fp);
    }

    // Đóng tập tin
    fclose(source_fp);
    fclose(destination_fp);

    printf("Đã sao chép '%s' sang '%s'\n", source_file, destination_file);

    return 0;
}
