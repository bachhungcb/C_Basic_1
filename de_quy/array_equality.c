#include <stdio.h>
#include <stdlib.h>

int ket_qua[1000];
int main(){
    int test_case;
    int a[1000];
    int b[1000];
    int n, m;
    scanf("%d", &test_case);
    for (int z = 0; z < test_case; z++){
        scanf("%d", &n);
        scanf("%d", &m);
        if(n != m){
            ket_qua[z] = 0;
        }else{
            int count = 0;
            for (int i = 0; i < n; i++){
                scanf("%d ", &a[i]);
            }for (int i = 0; i < m; i++){
                scanf("%d ", &b[i]);
            }
            for (int i = 0; i < n; i++){
                if (a[i] != b[i]){
                    count++;
                }
            }
            if (count != 0) ket_qua[z] = 0;
            else ket_qua[z] = 1;
        }
    }

    for (int z = 0; z < test_case; z++){
        printf("%d \n", ket_qua[z]);
    }
    
    return 0;
}