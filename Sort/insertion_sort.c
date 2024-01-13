#include <stdio.h>
#include <stdlib.h>

void insertionSort(int A[], int n){
    for (int i = 1; i < n; i++) {
        int last = A[i];
        int j = i;
        while(j>= 0 && A[j-1] > last){
            A[j] = A[j-1];
            j--;
        }
        A[j] = last;
    }
}

int main(){
    int n;
    scanf("%d",&n);
    int A[100];
    for (int i = 0; i < n; i++){
        scanf("%d", &A[i]);
    }
    
    insertionSort(A, n);
    for(int i = 0; i<n;i++){
        printf("%d ", A[i]);
    }
    return 0;
}