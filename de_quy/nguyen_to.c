#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int nguyen_to(int n){
    if (n == 1) return 1;
    for (int i = 2; i <= sqrt(n); i++){
        if (n % i == 0) return 1;
    }
    return 0;
}

int main(){
    int n;
    scanf("%d", &n);
    if (!nguyen_to(n)) {
        for (int i = 2; i <= n; i++)
        {
            printf("%d ",i);
        }
        
    }
    else printf("%d KHONG la so nguyen to.", n);
    return 0;
}