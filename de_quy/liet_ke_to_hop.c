#include <stdio.h>
#include <stdlib.h>

int n, x[100];
int count = 0;
int k;


void print_solution(int k){
    for (int j = 1; j <= k; j++){
        printf("%d ", x[k]);
    }
    printf("\n");
}

int TRY (int i){
    for(int v = x[i - 1] + 1; v <= n - k + i;v++){
        count++;
        x[i] = v; 
        if (i == k) print_solution(k);
        else TRY(i+1);
    }
}

int main(){
    printf("Nhap vao to hop can tinh:\n");
    k = 2;
    n = 20;
    TRY(1);
    printf("%d",count);
    return 0;
}
