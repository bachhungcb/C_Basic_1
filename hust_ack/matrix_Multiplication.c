#include <stdio.h>
#include <stdlib.h>

int main(){
    int n, k, p, m;
    int A[100][100];
    int B[100][100];
    int ket_qua[100][100];

    scanf("%d %d", &n, &k);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < k; j++){
            scanf("%d", &A[i][j]);
        }
    }

    scanf("%d %d", &p, &m);
    for(int i = 0; i < p; i++){
        for(int j = 0; j < m; j++){
            scanf("%d", &B[i][j]);
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < k; j++){
            for(int a = 0; a < m; a++){
                for(int b = 0; b < p; b++){
                    ket_qua[i][m] = A[i][j] * B[a][b];
                }
            }
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; i < m; j++){
            printf("%d ", ket_qua[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}