#include <stdio.h>
#include <stdlib.h>

int n, x[100];

void print_solution(){
    for(int i = 1; i <= n; i++){
        printf("%d", x[i]);
    }
    printf("\n");
}

void Try(int k){
    for(int i = 0; i <= 1; i++){
        if(x[k-1] + i < 2){
            x[k] = i;
            if(k == n)
                print_solution();
            else
                Try(k+1);
        }
    }
}

int main(){
    scanf("%d", &n);
    Try(1);
    return 0;
}