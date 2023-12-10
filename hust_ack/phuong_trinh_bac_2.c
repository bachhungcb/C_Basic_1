#include <math.h>
#include <stdio.h>
int main() {
    int a,b,c;
    double delta, x1, x2;
    scanf("%d %d %d", &a, &b, &c);
    delta = b*b - 4*a*c;

    if(delta > 0){
        x1 = (-b - sqrt(delta))/(2*a);
        x2 = (-b + sqrt(delta))/(2*a);
        printf("%.2lf %.2lf", x1, x2);
    }

    if(delta == 0){
        x1 = -b/(2*a);
        printf("%.2lf", x1);
    }

    if (delta < 0){
        printf("NO SOLUTION");
    }
    
    return 0;
}
