#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <conio.h>

struct phone {
    char model[50];
    int memory_space;
    double screen_size;
    double price;
};

struct phone *danh_sach_dien_thoai = NULL; // Initialize to NULL
int so_luong_dien_thoai;
enum {SUCCESS, FAIL};

// Function prototypes
int doc_bang_phone(const char *filename, struct phone **danh_sach_dien_thoai, int *so_luong_dien_thoai);
void chuc_nang_1(const char *filename, struct phone *danh_sach_dien_thoai, int so_luong_dien_thoai);
void chuc_nang_2(const char *filename,struct phone *danh_sach_dien_thoai, int so_luong_dien_thoai);
void chuc_nang_3(struct phone *danh_sach_dien_thoai, int so_luong_dien_thoai);
void chuc_nang_4(struct phone *danh_sach_dien_thoai, int so_luong_dien_thoai);
int menu();

int main() {
    // Read student data from the phoneDb.txt
    if (!doc_bang_phone("phoneDb.txt", &danh_sach_dien_thoai, &so_luong_dien_thoai)) {
        printf("Khong the doc du lieu tu tep.\n");
        return 1;
    }

    while (1) {
        int n = menu();
        switch (n) {
        case 1:
            chuc_nang_1("phonedb.dat", danh_sach_dien_thoai, so_luong_dien_thoai);
            break;

        case 2:
            chuc_nang_2("phonedb.dat",danh_sach_dien_thoai, so_luong_dien_thoai);
            break;

        case 3:
            chuc_nang_3(danh_sach_dien_thoai, so_luong_dien_thoai);
            break;

        case 4:
            chuc_nang_4(danh_sach_dien_thoai, so_luong_dien_thoai);
            break;

        case 5:
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
    printf("4. Search by phone by Phone Model \n");
    printf("5. Quit\n");
    printf("Vui long chon chuc nang: ");
    scanf("%d", &n);
    return n;
}


int doc_bang_phone(const char *filename, struct phone **danh_sach_dien_thoai, int *so_luong_dien_thoai) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        return 0;
    }

    fscanf(file, "%d", so_luong_dien_thoai);

    *danh_sach_dien_thoai = (struct phone *) malloc((*so_luong_dien_thoai) * sizeof(struct phone));
    if (!*danh_sach_dien_thoai) {
        fclose(file);
        return 0;
    }

    for (int i = 0; i < *so_luong_dien_thoai; i++) {
        fscanf(file, "%s %d %lf %lf", 
        (*danh_sach_dien_thoai)[i].model, &(*danh_sach_dien_thoai)[i].memory_space,
        &(*danh_sach_dien_thoai)[i].screen_size, &(*danh_sach_dien_thoai)[i].price);
    }

    fclose(file);
    return 1;
}

void chuc_nang_1(const char *filename, struct phone *danh_sach_dien_thoai, int so_luong_dien_thoai) {
    system("cls");
    FILE *fptr2;
    if ((fptr2 = fopen(filename, "wb")) == NULL) {
        printf("Khong the mo tep.\n");
    }

    fwrite(&so_luong_dien_thoai, sizeof(int), 1, fptr2);
    fwrite(danh_sach_dien_thoai, sizeof(struct phone), so_luong_dien_thoai, fptr2);

    fclose(fptr2);
}


void chuc_nang_2(const char *filename, struct phone *danh_sach_dien_thoai, int so_luong_dien_thoai){
    system("cls");
    FILE *fptr2;
    if ((fptr2 = fopen(filename, "r+b")) == NULL) {
        printf("Khong the mo tep.\n");
    }
    int n, c, irc;
    int reval = SUCCESS;
    
    if (fseek(fp, 1*sizeof(filename), SEEK_SET) != 0 ){
        printf("Fseek failed!\n");
    }

    irc = fread(danh_sach_dien_thoai, sizeof(filename), )

    fclose(fptr2);
}

void chuc_nang_3(struct phone *danh_sach_dien_thoai, int so_luong_dien_thoai) {
    system("cls");
    printf("Bang dien thoai:\n");
    for (int i = 0; i < so_luong_dien_thoai; i++) {
    printf("Model:%-10s Memory Space:%-10d Screen Size:%-10.2lf Price:%-10.2lf\n", 
            danh_sach_dien_thoai[i].model, danh_sach_dien_thoai[i].memory_space, danh_sach_dien_thoai[i].screen_size, danh_sach_dien_thoai[i].price);   
    }
    getch();
}

void chuc_nang_4(struct phone *danh_sach_dien_thoai, int so_luong_dien_thoai) {
    system("cls");
    char phone_model[50];
    double diem_moi;

    printf("Nhap vao ma dien thoai can tim: ");
    scanf("%s", &phone_model);

    int tim_thay = 0;
    for (int i = 0; i < so_luong_dien_thoai; i++) {
        if (!strcmp(danh_sach_dien_thoai[i].model, phone_model)) {
            if (tim_thay == 0) printf("Tim thay dien thoai:\n");
            printf("Model:%-10s Memory Space:%-10d Screen Size:%-10.2lf Price:%-10.2lf\n", 
            danh_sach_dien_thoai[i].model, danh_sach_dien_thoai[i].memory_space, danh_sach_dien_thoai[i].screen_size, danh_sach_dien_thoai[i].price);
            tim_thay ++;
            break;
        }
    }

    if (!tim_thay) {
        printf("Khong tim thay dien thoai can tim.\n");
        getch();
    }
    getch();
}
