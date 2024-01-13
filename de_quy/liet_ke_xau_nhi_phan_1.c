#include <stdio.h>
#include <stdlib.h>

int n, x[100];

void print_solution(){
    for(int k = 0; k < n; k++){
        printf("%d ",x[k]);
    }
    printf("\n");
}

int TRY(int k) {
    for(int v = 0; v <= 1; v++){
    if(x[k-1] + v < 2){
        x[k] = v;
        if(k == n - 1) 
            print_solution();
        else TRY(k+1);
    }
    }
}

int main(){
    scanf("%d", &n);
    TRY(0);
    return 0;
}