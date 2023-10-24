#include <stdio.h>
#include <stdlib.h>

int main(){
    int a[100];
    int b[100];
    int n, m;
    printf("Enter the size of array 1: ");
    scanf("%d", &n);
    printf("Enter the size of array 2: ");
    scanf("%d", &m);
    if(n != m){
        printf("0");
    }else{
        int count = 0;
        for (int i = 0; i < n; i++){
            scanf("%d", &a[i]);
        }for (int i = 0; i < m; i++){
            scanf("%d", &b[i]);
        }
        for (int i = 0; i < n; i++){
            if (a[i] != b[i]){
                count++;
            }
        }
        if (count != 0) printf("0");
        else printf("1");
    }
    
}