#include <stdio.h>

void split_num(double num, int *int_part, double *frac_part ){
    *int_part = (int)num;
    *frac_part= num - *int_part;
}


int main(void){
    double num, fraction;
    int integer;

    printf("Please enter a real number: ");
    scanf("%lf", &num);

    split_num(num, &integer,&fraction);
    printf("The integer part is: %d\n", integer);
    printf("The fraction part is: %lf\n", fraction);
    return 0;
}