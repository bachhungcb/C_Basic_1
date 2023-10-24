#include <stdio.h>
#include <stdlib.h>

int n, x[100];

void print_solution(){
    for (int j = 1; j <= n; j++){
        printf("%d ", x[j]);
    }
    printf("\n");
}

int check(int v, int k){
    for(int i = 1; i <= k-1; i++){
        if(x[i] == v) return 0;
        if(x[i] + i == v + k) return 0;
        if(x[i] - i == v - k) return 0;
    }
    return 1;
}

int TRY (int k){
    for(int v = 1; v <= n;v++){
        if (check(v,k)){ 
            x[k] = v;
            if (k == n){ print_solution();}
            else TRY(k+1);
        }
    }
}

int main(){
    printf("Nhap vao so N cua ban co NxN:\n");
    scanf("%d", &n);
    TRY(1);
    return 0;
}
