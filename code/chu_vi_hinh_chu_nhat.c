#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]){
    if(argc != 3){
        printf("Nhap vao thieu doi so.\n");
        printf("Correct syntax: rect <chieu_dai> <chieu_rong>\n");
        return 1;
    }
    double chieu_dai, chieu_rong;
    chieu_dai = atof(argv[1]);
    chieu_rong = atof(argv[2]);
    printf("chu vi la: %lf\ndien tich la: %lf\n", chieu_dai +chieu_rong, chieu_dai * chieu_rong);
    return 0;
}