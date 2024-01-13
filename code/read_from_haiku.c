#include <stdio.h>
#include <string.h>
#include <stdlib.h>

enum{SUCCESS, FAIL, MAX_LEN = 80};

int main(){
    int num;
    FILE *fptr2;
    char filename2[] = "haiku.txt";
    char buff[MAX_LEN + 1];
    int reval = SUCCESS;
    if((fptr2 = fopen(filename2, "r")) == NULL){
        printf("Khong mo duoc file.\n");
        reval = FAIL; exit(1);
    }
    num = fread(buff, sizeof(char), MAX_LEN, fptr2);
    buff[num * sizeof(char)] = '\0';

    printf("%s", buff);
    fclose(fptr2);
    return 0;
}