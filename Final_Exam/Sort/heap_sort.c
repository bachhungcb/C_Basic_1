#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int A[], int i, int N){
    int L = 2*i+1;
    int R = 2*i+2;
    int max = i;
    if(L < N && A[L] > A[i])
        max = L;
    if(R < N && A[R] > A[max])
        max = R;
    if(max != i){
        swap(&A[i], &A[max]);
        heapify(A, max, N);
    }
}

void buildHeap(int A[], int N){
    for(int i = N/2-1; i>=0; i--){
        heapify(A, i, N);
    }
}

void heapSort(int A[], int N){
    buildHeap(A, N);
    for(int i = N-1; i > 0; i--){
        swap(&A[0], &A[i]);
        heapify(A, 0, i);
    }
}

int main(){
    int A[31]={341,544,542,550,775,574,201,903,427,364,178,653,327,28,644,580,513,97,998,396,505,826,115,363,485,224,381,262,901,36,642};
    heapSort(A, 31);
    for(int i = 0; i < 31; i++){
        printf("%d->", A[i]);
    }
    return 0;
}