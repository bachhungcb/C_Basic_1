#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int n; int x[100];

void solution()
{
    for(int i=1;i<=n;i++)
        printf("%d", x[i]);
    printf("\n");
}

void back(int i)
{
    for(int j=0;j<=1;j++)
    {
        x[i] = j;
        if(i == n)
        {
            solution();
        }
        else back(i+1);
    }
}

int main(){
    scanf("%d", &n);
    back(1);
}
