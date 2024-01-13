#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b =temp;
}

int partition(int *A, int L, int R, int indexPivot){
    int pivot = A[indexPivot];
    swap(&A[indexPivot], &A[R]);
    int storedIndex = L;

    for(int i = L; i <= R; i++){
        if(A[i] < pivot){
            swap(&A[storedIndex], &A[i]);
            storedIndex++;
        }
    }

    swap(&A[storedIndex], &A[R]);
    return storedIndex;
}

void quickSort(int A[], int L, int R){
    if(L < R){
        int M = (L+R)/2;
        int index = partition(A,L,R,M);
        quickSort(A,L, index-1);
        quickSort(A,index+1,R);
    }
}

int main(){
    int A[] = {10,23,4,1,2,4,5,66,54};
    int n = sizeof(A)/sizeof(A[0]);
    quickSort(A,0,n-1);

    for(int i = 0; i<n;i++){
        printf("%d ", A[i]);
    }

    return 0;
}