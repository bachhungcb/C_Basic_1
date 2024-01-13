#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

int main(void){
    char alphabet[26] ={'A','B','C','D','E','F','G','H','I','J','K','L','M',
                        'N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
    char ma_hoa[26] ={'A','B','C','D','E','F','G','H','I','J','K','L','M',
                        'N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
    char string[100];
    printf("Nhap vao 1 xau: ");
    scanf("%s", string);
    
    int key, temp_index;
    printf("Nhap vao 1 key: ");
    scanf("%d", &key);
    for(int i = 0; string[i] != '\0'; i++){
        temp_index = 0;
        for(int j = 0; j < strlen(alphabet); j++){
            char upper_char = string[i];
            if(upper_char == alphabet[j]){
                printf("%c", ma_hoa[(j + key) % 26]);
                break;
            }
        }
        if (string[i] == ' ')    
        printf(" ");
    }
    return 0;
}