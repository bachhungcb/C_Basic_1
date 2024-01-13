#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void is_prime(int i, int n){
    if ( i > n) return;
        int count = 0;
        for (int j = 2; j <= sqrt(i); j++){
            if (i % j == 0){
                count++;
                break;
            }
        if (count == 0) printf("%d ", i);
        }
        is_prime(i+1, n);
    
}

int main(){
    int n;
    scanf("%d", &n);
    is_prime(2,n);
    return 0;
}

