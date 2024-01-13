#include <stdio.h>
#include <stdlib.h>


int main(){
    int i, n, *p;
    printf("How many number do you want to enter?\n");
    scanf("%d", &n);

    p = (int *)malloc(n * sizeof(int));
    if( p == NULL){
        printf("Memory allocation failed. \n");
        return 1;
    }

    for(i = 0; i < n; i++){
        scanf("%d", &p[i]);
    }

    for ( i = n - 1; i >= 0; i--)
    {
        printf("%d ", p[i]);
    }
    
    free(p);
    return 0;
}