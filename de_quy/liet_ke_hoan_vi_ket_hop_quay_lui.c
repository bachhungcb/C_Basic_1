#include <stdio.h>
#include <stdlib.h>

int n, x[100];
int count = 0;
int m[100] = {0};

void print_solution(){
    for (int j = 1; j <= n; j++){
        printf("%d ", x[j]);
    }
    printf("\n");
}

int TRY (int i){
    for(int v = 1; v <= n;v++){
        if(m[v] != 1){
            count++;
            x[i] = v; 
            m[v] = 1;
            if (i == n) print_solution();
            else TRY(i+1);
            m[v] = 0;
        }
    }
}

int main(){
    printf("Nhap vao to hop can tinh:\n");
    n = 4;
    TRY(1);
    printf("Can Dung: %d",count);
    return 0;
}
