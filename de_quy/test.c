#include <stdio.h>
#include <stdlib.h>

int n,x[100];

void printSolution(){
for(int k = 0; k < n; k++)
printf("%d",x[k]);
printf("\n"); 
}
int TRY(int k) {
for(int v = 0; v <= 1; v++){
x[k] = v;
if(k == n-1) printSolution();
else TRY(k+1);
}
}
int main() {
scanf("%d", &n);
TRY(0);
}
