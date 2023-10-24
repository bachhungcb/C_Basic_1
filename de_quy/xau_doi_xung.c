#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int dao_nguoc(char *s, int bat_dau, int ket_thuc){

    if ( bat_dau >= ket_thuc) return 0;
    if (s[bat_dau] != s[ket_thuc -1]) return 1;
    return dao_nguoc(s, bat_dau + 1, ket_thuc - 1);
}

int main(){
    char string[100] = {"abcabcbacba"};
    int len;
    len = strlen(string);
    if(!dao_nguoc(string, 0, len)) printf("Xau la xau dao nguoc");
    else printf("Xau KHONG la xau dao nguoc");
    return 0;
}