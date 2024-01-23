
#include <stdio.h>
#include <stdlib.h>

int KiemTra(int so)
{
for (int i = 2; i<so; i++)
if (so%i == 0)
return 0;
return 1;
}
int TinhTong(int N)
{ int so = 2; int tong = 0; int dem = 0; while (dem <N)
{
if (KiemTra(so) == 1)
{
tong = tong + so;
dem ++;
}
so = so + 1;
}
return tong;
}

int main(){
    printf("%d ", TinhTong(9));
    return 0;
}