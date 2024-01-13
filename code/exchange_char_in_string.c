#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

void exchange_char(char a[], char b, char c){
    for (int i = 0; a[i] !='\0'; i++){
        if(a[i] == b){
            a[i] = c;
        }
    }
}


int main(){
    char myString[100];
    char a,b;
    printf("Nhap vao xau dau vao: ");
    scanf("%s", &myString);
    printf("Nhap vao 2 ky tu:");
    scanf(" %c %c", &a,  &b);
    exchange_char(myString, a,b);
    printf("%s", myString);
    return 0;
}

