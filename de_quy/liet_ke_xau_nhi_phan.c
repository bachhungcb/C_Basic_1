#include <stdio.h>
#include <stdlib.h>

int n, x[100];

void print_solution(){
    for(int k = 1; k <= n; k++){
        printf("%d",x[k]);
    }
    printf("\n");
}

void try(int k){
    for (int i = 0; i <= 1; i++)
    {
        x[k] = i;
        if(k == n){
            print_solution();
        }else try(k+1);
    }
}

int main(){
    scanf("%d", &n);
    try(1);
}