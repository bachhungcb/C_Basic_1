#include <stdio.h>
#include <stdlib.h>

int n, x[100];
int m[100] = {0};

void print_solution(){
    for(int i = 1;i <= n; i++){
        printf("%d ",x[i]);
    }
    printf("\n");
}

void Try(int k){
    for(int i = 1; i <= n; i++){
        if(m[i] != 1){
        x[k] = i;
        m[i] = 1;
        if(k == n) print_solution();
        else Try(k+1);
        m[i] = 0;
        }
    }
}

int main(){
    scanf("%d", &n);
    Try(1);
    return 0;
}