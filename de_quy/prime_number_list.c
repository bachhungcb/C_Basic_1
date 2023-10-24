#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void is_prime(int n){
    for(int i = 2; i <= sqrt(n); i++)
        if (n % i == 0)
        {
            printf("%d is not a prime number\n", n);
            return;
        }
    printf("%d", n);
}

int main(){
    int n;
    scanf("%d", &n);
    is_prime(n);
    return 0;
}

