#include <stdio.h>
#include <stdlib.h>

void selectionSort(int A[], int n){
    for(int i = 0;i <= n;i++){
        int min = i;
        for(int j = i+1;j <= n;j++){
            if(A[min] >A[j]) min = j;
        }
        int temp = A[min];
        A[min] = A[i];
        A[i] = temp;
    }
}

int main(){
    int A[5]={5,4,2,1,6};
    int n=sizeof(A)/sizeof(A[0]);
    selectionSort(A, n);
    for(int i =0; i<n;i++){
        printf("%d ",A[i]);
    }
    return 0;
}