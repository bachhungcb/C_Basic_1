#include <stdio.h>
#include <math.h>

#define EPSILON 0.000001

int findRoots(int a, int b, int c, int d) {
    int cnt = 0;
    for (double i = -100; i <= 100; i += EPSILON) {
        if (fabs(a*i*i*i + b*i*i + c*i + d) <= EPSILON) {
            printf("%.1f ", i);
            cnt++;
        }
    }
    if(cnt != 0)
        return 1;
    else
        return 0;
}

int main() {
    int b, c, d;
    scanf("%d %d %d", &b, &c, &d);

    if(findRoots(1, b, c, d) == 1){
        findRoots(1, b, c, d);
    }else{
        printf("NO SOLUTION");
    }
    return 0;
}