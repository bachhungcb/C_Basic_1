#include <stdio.h>
#include <stdlib.h>

int my_array[1000000];

int main(){
    int n,sum;
    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        scanf("%d ", &my_array[i]);
    }
    sum = 0;

    for(int i = 0; i < n; i++){
        sum += my_array[i];
    }

    printf("%d", sum);
    return 0;
}