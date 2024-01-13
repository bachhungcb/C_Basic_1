#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LEN 1000

char* my_strcat (char* str1, char* str2){
    int len1, len2; char* result;
    len1 = strlen(str1); len2 = strlen(str2);
    result = (char*)malloc((len1 + len2 +1) * sizeof(char));
    if(result == NULL){
        printf("Memory allocation failed.");
        return NULL;
    }
    strcpy(result , str1 );
    strcpy(result + len1, str2);
    return result;
}

int main(int argc, char* argv[]){
    if (argc != 3)
    {
        printf("Nhap sai doi so.\n");
        printf("Vui long nhap theo cu phap: <ten chuong trinh> <\"string 1\"> <\"string 2\">");
        return 1;
    }
    
    char* string1 = argv[1];
    char* string2 = argv[2];
    char *cat_str;

    cat_str = my_strcat(string1,string2);
    printf("Xau ghep tu 2 xau tren la: %s ", cat_str);
    free(cat_str);
    return 0;
}