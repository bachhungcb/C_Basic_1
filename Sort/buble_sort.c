#include <stdio.h>
#include <stdlib.h>

void bubleSort(int A[], int n){
    int swapped;
    do{
        swapped = 0;
        for(int i = 0; i<n-1; i++){
            if(A[i] > A[i+1]){
                int temp = A[i];
                A[i] = A[i+1];
                A[i+1] = temp;
                swapped = 1;
            }
        }
        }while(swapped == 1);
    }
int main(){
    int n;
    scanf("%d",&n);
    int A[100];
    for (int i = 0; i < n; i++){
        scanf("%d", &A[i]);
    }
    
    bubleSort(A, n);
    for(int i = 0; i<n;i++){
        printf("%d ", A[i]);
    }
    return 0;
}