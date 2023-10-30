#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void replace_char(char *s, char from, char to ){
    int len = strlen(s);
    for(int i = 0; i < len; i++){
        if(s[i] == from) s[i] = to;
    }
}

int main(){
    char mystring[100];
    char from_char, to_char;
    //printf("Nhap vao mot xau: ");
    scanf("%s", mystring);
    getchar();

    //printf("Nhap vao ky tu can chuyen: ");
    scanf("%c", &from_char);
    getchar();

    //printf("Nhap vao ky tu muon chuyen: ");
    scanf("%c", &to_char);
    getchar();

    replace_char(mystring, from_char,to_char);

    printf("%s", mystring);
    return 0;
}