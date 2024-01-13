#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char* argv[]){
    if(argc != 2){
        printf("Nhap sai doi so, \n");
        printf("vui long nhap theo cu phap: <ten chuong trinh> <gia tri luy thua>");
        return 1;
    }
    int luy_thua;
    luy_thua = atof(argv[1]);
    printf("e^%d = %lf", luy_thua, exp(luy_thua));
    return 0;
}