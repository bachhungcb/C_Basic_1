#include <stdio.h>
#include <stdlib.h>

int fibonaci(int n){
    if(n >= 1){
        return fibonaci(n-1) + fibonaci(n-2);
    }else return 1;
}

int main(){
    for (int i = 0; i <= 10; i++)
    {
        printf("%d ", fibonaci(i));
    }
    return 0;
}