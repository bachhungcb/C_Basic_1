#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char str1[256] = "10:35:20";
    char str2[256] = "10:35:19";
    printf("%d", strcmp(str2, str1));// -1 la be hon 1 la lon hon
    return 0;
}