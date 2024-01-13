#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define REP(i,a,b) for(int i=a;i<=b;i++)

int main(int argv, char* args[])
{
    double i;
    i = atof(args[1]);
    printf("%d\n", (int) i);
    printf("%lf", i - (int)i);
    return 0;
}
