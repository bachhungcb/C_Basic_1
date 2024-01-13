#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* sub_str(char* s1, int offset, int number){
    char *result;
    int len_s1;
    len_s1 = strlen(s1);
    result = (char*)malloc((len_s1 + 1) * sizeof(char));
    if(offset < 0 || offset > strlen(s1) || number < 0){
        printf("Gia tri nhap vao cua offset hoac number khong hop le");
        return NULL;
    }

    if(result == NULL){
        printf("Error: memory allocation failed.\n");
        return NULL;
    }
    
    if(number < len_s1){
        for (int i = offset; i < number; i++)
        {
            strcpy(result, s1 + offset);
        }
        result[number] = '\0';
    }else{
        strcpy(result, s1 + offset);
    }
    return result;
}


int main (int argc, char* argv[]){
    if (argc != 4){
        printf("Doi so nhap vao khong hop le.\n");
        printf("Nhap vao doi so theo cu phap: <ten chuong trinh> <xau ky tu> <offset> <number>\n ");
        return 1;
    }
    
    int offset, number;
    char *sub_string;
    char* my_string = argv[1];
    offset = atoi(argv[2]);
    number = atoi(argv[3]);
    sub_string = sub_str(my_string, offset, number);


    if (sub_str == NULL)
    {
        printf("Problem allocating Memoy!");
        return 1;
    }

    printf("%s\n", sub_string);
    free(sub_string);
    
    return 0;
}