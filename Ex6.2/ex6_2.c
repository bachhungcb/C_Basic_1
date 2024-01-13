#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char *latname[] = {"A", "B", "C", "D", "E"};

void generateRandomProfile(FILE *file, int i) {
    char *first_name = "Nguyen";
    char *last_name = latname[i];

    time_t t = time(NULL);
    struct tm birthdate = *localtime(&t);
    birthdate.tm_year -= rand() % (60 - 20 + 1) + 20;

    fprintf(file, "%s %s\n", first_name, last_name);
    fprintf(file, "%d-%02d-%02d\n", birthdate.tm_year + 1900, birthdate.tm_mon + 1, birthdate.tm_mday);
}

int main() {
    int n = 5;
    char file_name[20];
    sprintf(file_name, "profile-%d.txt", n);

    FILE *file = fopen(file_name, "w");

    if (file == NULL) {
        fprintf(stderr, "Không thể mở file để ghi.\n");
        return 1;
    }

    for (int i = 0; i < n; ++i) {
        generateRandomProfile(file, i);
    }

    fprintf(file, "#");
    fclose(file);

    printf("%d hồ sơ đã được tạo và lưu vào file %s.\n", n, file_name);

    return 0;
}
