#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// #define MAX_STUDENTS 10000

struct student {
    int stt;
    char name[50];
    char mssv[10];
    double grade;
};

int compare_students(const void *a, const void *b) {
    struct student *s1 = (struct student *)a;
    struct student *s2 = (struct student *)b;

    char *first1, *middle1, *last1;
    char *saveptr1 = NULL;

    char *first2, *middle2, *last2;
    char *saveptr2 = NULL;
    char name1[50], name2[50];
    strcpy(name1, s1->name);
    strcpy(name2, s2->name);

    first1 = strtok_r(name1, " ", &saveptr1);
    middle1 = strtok_r(NULL, " ", &saveptr1);
    last1 = strtok_r(NULL, " ", &saveptr1);

    first2 = strtok_r(name2, " ", &saveptr2);
    middle2 = strtok_r(NULL, " ", &saveptr2);
    last2 = strtok_r(NULL, " ", &saveptr2);
    
    int last_cmp = strcmp(last1,last2);
    if(last_cmp != 0) {
        return last_cmp;
    }

    int middle_cmp = strcmp(middle1,middle2);
    if(middle_cmp != 0) {
        return middle_cmp;
    }

    return strcmp(first1,first2);
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

int compare_student_by_student_id(const void *a, const void *b){
    struct student *s1 = (struct student *)a;
    struct student *s2 = (struct student *)b;

    int mssv1 = atoi(s1->mssv);
    int mssv2 = atoi(s2->mssv);
     if(mssv1 < mssv2){
        return -1;
     }else if(mssv1 > mssv2){
        return 1;
     }else{
        //if mss1 is equal to mssv2
        if(s1->stt < s2->stt){
            return -1;
        }else if(s1->stt > s2->stt){
            return 1;
        }else{
            return 0;
        }
}
}

int main() {
    int n, i;
    char sort_by;
    char line[256], *saveptr;
    char *token;
    scanf("%d %c", &n, &sort_by);
    getchar();

    struct student *students = (struct student *)malloc(n * sizeof(struct student));
    
    for (i = 0; i < n; i++) {
       fgets(line, 256, stdin);

        token = strtok_r(line, "*", &saveptr);
        students[i].stt = atoi(token);

        token = strtok_r(NULL, "*", &saveptr);
        strcpy(students[i].name, token);

        token = strtok_r(NULL, "*", &saveptr);
        strcpy(students[i].mssv, token);

        token = strtok_r(NULL, "*", &saveptr);
        students[i].grade = atof(token);
    }

    if (sort_by == 'n') {
        qsort(students, n, sizeof(struct student), compare_students);
    } else if (sort_by == 'g') {
        qsort(students, n, sizeof(struct student), compare_students_by_grade_desc);
    } else if (sort_by == 'c') {
        qsort(students, n, sizeof(struct student), compare_student_by_student_id);
    }

    for (i = 0; i < n; i++) {
        printf("%d*%s*%s*%.2lf\n", students[i].stt, students[i].name, students[i].mssv, students[i].grade);
    }

    free(students);
    return 0;
}