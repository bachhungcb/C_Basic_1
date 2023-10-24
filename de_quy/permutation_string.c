#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int n;
char ABC[3] =  "ABC";

void swap(char *x, char *y){
    char temp = *x;
    *x = *y;
    *y = temp;
}

//This function takes 3 parameter:
//1.String name
//2.Start index
//3.End index
void try(char *a, int l, int r){
    if(l == r)printf("%s\n", a);
    else{
        for(int i = l; i <=r; i++){
            swap((a + l), (a + i));
            try(a, l + 1, r);
            swap((a + l), ( a+ i)); //backtrack
        }
    }
}

int main(){
    int n = strlen(ABC);
    try(ABC, 0, n-1);
    return 0;  
}