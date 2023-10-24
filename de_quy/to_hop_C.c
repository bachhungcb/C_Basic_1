#include <stdio.h>
#include <stdlib.h>

int count = 0;
int C(int k, int n){
    count++;
    if(k == 0 || k == n) return 1;
    else return C(k, n-1) + C(k-1, n-1);
}

int main(){
    printf("9C3 = %d", C(3,9));
    printf("\nSo lan goi de quy o de quy khong nho: %d", count);
    return 0;
}