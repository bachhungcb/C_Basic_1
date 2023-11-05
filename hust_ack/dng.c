#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
    char s[1000];
    fgets(s, 1000, stdin);
    int i = 0;
    int length = strlen(s);
    int s2[length];
    int j = 0;
    
    while (j < length){
        if (s[j]=='(' || s[j]=='[' || s[j]=='{'){
            s2[i] = s[j];
            i++;
        }
        else if (s[j]==')'){
            if (s2[i-1] == '(') i--;
            else 
            {
                break;
            }
        }
        else if (s[j]==']'){
            if (s2[i-1] == '[') i--;
            else 
            {
            
                break;
            }
        }
        else if (s[j]=='}'){
            if (s2[i-1] == '{') i--;
            else 
            {
               
                break;
            }
        }
        j++;
    }
    if (i==0 && j == length) printf("1");
    else printf("0");

    return 0;
}
