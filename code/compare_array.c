    #include <stdio.h>
    #include <stdlib.h>


    int compare_array(int* a, int*b, int n){
        int sum = 0;
        int doi_xung = 0;
        for (int i = 0; i < n; i++){
            if(a[i] != b[i]){
                sum++;
            }
            if(a[i] != b[n-i-1]){
                doi_xung++;
            }
        }
        if (sum == 0){
            return 1;
        }
        if (doi_xung == 0){
            return -1;
        }
            return 0;
    }

    int main(){
        int n;
        printf("Nhap vao so phan tu cua mang: ");
        scanf("%d", &n);
        int* array_a = (int*)malloc(n * sizeof(int));
        int* array_b = (int*)malloc(n * sizeof(int));

        for (int i = 0; i < n; i++){
            printf("Nhap vao phan thu thu %d cua mang 1:", i+1);
            scanf("%d", &array_a[i]);
        }
        for (int i = 0; i < n; i++){
            printf("Nhap vao phan thu thu %d cua mang 2:", i+1);
            scanf("%d", &array_b[i]);
        }
        printf("%d", compare_array(array_a,array_b,n));
        free(array_a);
        free(array_b);
        return 0;
    }
