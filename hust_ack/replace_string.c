#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char* replace_string(char *s, char *from, char *to){
    char *pos, temp[1000];
    long long int from_len = strlen(from);
    long long int index;

    while ((pos = strstr(s,from)) != NULL){
        strcpy(temp, s);

        index = pos - s; // voi s la con tro tro den vi tri dau tien cua xau
                         // va pos la con tro tro den vi tri dau tien cua tu can thay doi
                         //index se la vi tri can chen 
        
        s[index] = '\0'; //ket thuc xau tai vi tri dau tien cua xau 
                         //de tien hanh chen tu can thay doi vao

        strcat(s, to);

        strcat(s, temp + from_len + index);
    }
    
}

int main(){
    char mystring[1000];
    char from_string[1000];
    char to_string[1000];

    scanf("%s", from_string);
    getchar();
    
    fgets(to_string, 1000, stdin);

    fgets(mystring, 1000, stdin);

    replace_string(mystring, from_string, to_string);
    printf("%s", mystring);
    return 0;
}