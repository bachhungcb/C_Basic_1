#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 100

struct student {
    int stt;
    char name[50];
    char mssv[10];
    double grade;
};

int compare_students(const void *a, const void *b) {
    struct student *s1 = (struct student *)a;
    struct student *s2 = (struct student *)b;

    if (strcmp(s1->name, s2->name) == 0) {
        return s1->stt - s2->stt;
    } else {
        return strcmp(s1->name, s2->name);
    }
}

int compare_students_by_grade_desc(const void *a, const void *b) {
    struct student *s1 = (struct student *)a;
    struct student *s2 = (struct student *)b;

    if (s1->grade < s2->grade) {
        return 1;  // s1 should come after s2
    } else if (s1->grade > s2->grade) {
        return -1; // s1 should come before s2
    } else {
        return s1->stt - s2->stt;
    }
}


int main() {
    struct student students[MAX_STUDENTS];
    int n, i;
    char sort_by;

    scanf("%d %c", &n, &sort_by);
    getchar();

    for (i = 0; i < n; i++) {
        scanf("%d* %[^*] %*c %[^*] %*c %lf", &students[i].stt, students[i].name, students[i].mssv, &students[i].grade);
        getchar();
    }

    if (sort_by == 'n') {
        qsort(students, n, sizeof(struct student), compare_students);
    } else if (sort_by == 'g') {
        qsort(students, n, sizeof(struct student), compare_students_by_grade_desc);
    } else if (sort_by == 'c') {
        qsort(students, n, sizeof(struct student),
            (int (*)(const void *, const void *))strcmp);
    }

    for (i = 0; i < n; i++) {
        printf("%d*%s*%s*%.1lf\n", students[i].stt, students[i].name, students[i].mssv, students[i].grade);
    }

    return 0;
}