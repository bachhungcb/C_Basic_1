#include <stdio.h>
#include <stdlib.h>

int main(){
    int myArray[1000][1000];
    int n, m;
    int dap_an = 0;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++){
        for (int j = 0 ; j < m; j++) {
            scanf("%d", &myArray[i][j]);
        }
    }

    for(int i = 0; i < n; i++){
        int count = 0;
        for (int j = 0 ; j < m; j++) {
            if(myArray[j][i] == 0) count++;
        }
        if(count == 0) dap_an++;
    }

    printf("%d", dap_an);
    return 0;
}