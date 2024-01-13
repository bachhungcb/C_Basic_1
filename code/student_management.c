#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <conio.h>

struct SinhVien {
    int mssv;
    char ten[50];
    double diem;
};

struct SinhVien *danh_sach_sinh_vien = NULL; // Initialize to NULL
int so_luong_sinh_vien;
enum { SUCCESS, FAIL };

// Function prototypes
int doc_bang_diem(const char *filename, struct SinhVien **danh_sach_sinh_vien, int *so_luong_sinh_vien);
void chuc_nang_1(const char *filename, struct SinhVien *danh_sach_sinh_vien, int so_luong_sinh_vien);
void chuc_nang_2(struct SinhVien *danh_sach_sinh_vien, int so_luong_sinh_vien);
void chuc_nang_3(struct SinhVien *danh_sach_sinh_vien, int so_luong_sinh_vien);
int menu();

int main() {
    // Read student data from the bangdiem.txt
    if (!doc_bang_diem("bangdiem.txt", &danh_sach_sinh_vien, &so_luong_sinh_vien)) {
        printf("Khong the doc du lieu tu tep.\n");
        return 1;
    }

    while (1) {
        int n = menu();
        switch (n) {
        case 1:
            chuc_nang_1("grade.dat", danh_sach_sinh_vien, so_luong_sinh_vien);
            break;

        case 2:
            chuc_nang_2(danh_sach_sinh_vien, so_luong_sinh_vien);
            break;

        case 3:
            chuc_nang_3(danh_sach_sinh_vien, so_luong_sinh_vien);
            break;

        case 4:
            free(danh_sach_sinh_vien); // Free dynamically allocated memory before exiting
            exit(0);
        }
    }
    return 0;
}

// ... (rest of your code)


int menu() {
    system("cls");
    int n;
    printf("1. TextToDat\n");
    printf("2. Display Dat file\n");
    printf("3. Search and Update\n");
    printf("4. Quit\n");
    printf("Vui long chon chuc nang: ");
    scanf("%d", &n);
    return n;
}


int doc_bang_diem(const char *filename, struct SinhVien **danh_sach_sinh_vien, int *so_luong_sinh_vien) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        return 0;
    }

    fscanf(file, "%d", so_luong_sinh_vien);

    *danh_sach_sinh_vien = (struct SinhVien *) malloc((*so_luong_sinh_vien) * sizeof(struct SinhVien));
    if (!*danh_sach_sinh_vien) {
        fclose(file);
        return 0;
    }

    for (int i = 0; i < *so_luong_sinh_vien; i++) {
        fscanf(file, "%d %s %lf", &(*danh_sach_sinh_vien)[i].mssv, (*danh_sach_sinh_vien)[i].ten, &(*danh_sach_sinh_vien)[i].diem);
    }

    fclose(file);
    return 1;
}

void chuc_nang_1(const char *filename, struct SinhVien *danh_sach_sinh_vien, int so_luong_sinh_vien) {
    system("cls");
    FILE *fptr2;
    if ((fptr2 = fopen(filename, "wb")) == NULL) {
        printf("Khong the mo tep.\n");
    }

    fwrite(&so_luong_sinh_vien, sizeof(int), 1, fptr2);
    fwrite(danh_sach_sinh_vien, sizeof(struct SinhVien), so_luong_sinh_vien, fptr2);

    fclose(fptr2);
}

void chuc_nang_2(struct SinhVien *danh_sach_sinh_vien, int so_luong_sinh_vien) {
    system("cls");
    printf("Bang diem:\n");
    for (int i = 0; i < so_luong_sinh_vien; i++) {
        printf("MSSV:%-5d Ten:%-8s Diem:%6.2f\n", danh_sach_sinh_vien[i].mssv, danh_sach_sinh_vien[i].ten, danh_sach_sinh_vien[i].diem);
    }
    getch();
}

void chuc_nang_3(struct SinhVien *danh_sach_sinh_vien, int so_luong_sinh_vien) {
    system("cls");
    int mssv;
    double diem_moi;

    printf("Nhap vao ma so sinh vien can tim: ");
    scanf("%d", &mssv);

    int tim_thay = 0;
    for (int i = 0; i < so_luong_sinh_vien; i++) {
        if (danh_sach_sinh_vien[i].mssv == mssv) {
            printf("Tim thay sinh vien:\n");
            printf("MSSV:%-5d Ten:%-8s Diem:%6.2f\n", danh_sach_sinh_vien[i].mssv, danh_sach_sinh_vien[i].ten, danh_sach_sinh_vien[i].diem);
            printf("Nhap diem moi: ");
            scanf("%lf", &diem_moi);
            danh_sach_sinh_vien[i].diem = diem_moi;
            tim_thay = 1;
            break;
        }
    }

    if (!tim_thay) {
        printf("Khong tim thay sinh vien can tim.\n");
        getch();
    }
    
}
