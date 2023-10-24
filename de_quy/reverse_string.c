#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reverse_string (char *str, int start, int end){
    if(start >= end) return;

    char temp = str[start];
    str[start] = str [end];
    str[end] = temp;

    reverse_string(str, ++start , --end); 
}

int main(){
    char str[]="Hello World";
    reverse_string(str, 0, strlen(str) - 1);
    printf("%s", str);
    return 0;
}