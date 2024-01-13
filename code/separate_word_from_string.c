#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
    char string[100];
    fgets(string, 100, stdin);
    for (int i = 0; string[i] != '\0'; i++){
        if(string [i] != ' '){
            printf("%c", string[i]);
        }else{
            if(string[i+1] != ' '){
                printf("\n");
            }
        }
    }
    return 0;
}
