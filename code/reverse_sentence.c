#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
-Run a for loop to traverse the string and create a temporary string to store the words
-If the current character is a space then add the current string to the answer and empty the string
-Else push the character into the string
-Print the answer array in reverse order 
*/

void reverse(char* begin, char* end){ //dao chieu cac chu cai trong string
    char temp;
    while (begin < end){
        temp = *begin;
        *begin++ = *end;
        *end-- = temp;
    }
}

void reverse_word(char *s){
    char* word_begin = s;

    //word boundary
    char* temp = s; //tro den ky tu dau tien cua xau

    while (*temp){
        temp++;
        if(*temp =='\0'){
            reverse(word_begin,temp - 1);
        }
        else if(*temp == ' '){
            reverse(word_begin, temp - 1);
            word_begin = temp + 1;
        }
    }

    //dao nguoc toan bo xau s
    reverse(s, temp - 1);
}

int main(int argc, char* argv[]){
    if(argc != 2){
        printf("Doi so nhap vao khong hop le.\n");
        printf("vui long nhap nhu sau: reverse_sentence <\"Cau van can nhap\">");
        return 1;
    }
    char* s = argv[1];
    reverse_word(s);
    printf("%s", s);
    return 0;
}