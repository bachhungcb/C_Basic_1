#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *my_strcat(char *s1, char *s2){
    int len_s1, len_s2;
    char *result;
    len_s1 = strlen(s1);
    len_s2 = strlen(s2);
    result = (char*)malloc((len_s1 + len_s2 + 1) * sizeof(char));
    if(result == NULL){
        printf("Allocation failed, check memory\n");
        return NULL;
    }
    strcpy(result, s1);
    strcat(result + len_s1, s2);
    return result;
}

int main(){
    char s1[100] = {"1"};
    char s2[100] = {"_2"};
    char *cat_str;
    cat_str = my_strcat(s1, s2);
    if (cat_str == NULL)
    {
        printf("Problem allocating Memoy!");
        return 1;
    }
    
    printf("%s\n", cat_str);
    free(cat_str);
    return 0;
}