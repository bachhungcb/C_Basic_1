#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

int main(){
    int n, cnt;
    int maxCnt = 0;
    int minLength = INT_MAX;
    scanf("%d", &n);
    int histogram[n];

    for(int i = 0; i < n; i++){
        scanf("%d", &histogram[i]);
    }

     for(int i = 1; i <=n; i++){
        
        if(abs(histogram[i-1] - histogram[i]) <=1){
            cnt++;
            
            if(cnt > maxCnt){
                maxCnt = cnt;
            }
            
            if(histogram[i-1] < minLength)
                minLength = histogram[i-1];

        }else{
            cnt = 0;
        }
    }

    printf("\n%d\n", (maxCnt + 1) * minLength);
    //printf("%d\n", maxCnt);
    //printf("%d\n", minLength);

    return 0;
}