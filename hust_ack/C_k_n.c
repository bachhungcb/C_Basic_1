#include <stdio.h>

int M[100][100] = {0};

int Ckn(int k, int n){
    if(k == 0|| k == n) return M[k][n] = 1;
    else if(M[k][n] == 0){
        M[k][n] = Ckn(k-1,n-1) + Ckn(k, n-1);
    }
    return M[k][n];
}

int main(){
    int n,k;
    scanf("%d %d", &k, &n);
    printf("%d", Ckn(k,n));
    return 0;
}