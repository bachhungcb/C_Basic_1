#include <stdio.h>
#include <stdlib.h>

void selectionSort(int A[], int n){
    for(int i = 0;i < n-1;i++){
        int min = i;
        for(int j = i+1;j < n;j++){
            if(A[min] >A[j]) min = j;
        }
        int temp = A[min];
        A[min] = A[i];
        A[i] = temp;
    }
}

int main(){
    int n;
    scanf("%d",&n);
    int A[100];
    for (int i = 0; i < n; i++){
        scanf("%d", &A[i]);
    }
    
    selectionSort(A, n);
    for(int i = 0; i<n;i++){
        printf("%d ", A[i]);
    }
    return 0;
}