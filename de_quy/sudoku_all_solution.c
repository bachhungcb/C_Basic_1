#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 9

//ham in ra ket qua
void print(int arr[N][N]){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

//ham kiem tra sudoku co dung hay khong
int is_safe(int arr[N][N], int hang, int cot, int num){
    
    //kiem tra xem co trung so tren cung 1 hang hay khong
    for (int i = 0; i < hang; i++)
        if (arr[hang][i] == num) return 0;

    //kiem tra xem co trung so tren cung 1 cot hay khong
    for (int i = 0; i < cot; i++)
        if(arr[i][cot] == num) return 0;

    //kiem tra ma tran 3x3 xem co trung so trong ma tran do hay khong
    int hang_bat_dat = hang - hang % 3;
    int cot_bat_dau = cot - cot % 3;

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(arr[hang_bat_dat + i][cot_bat_dau + j] == num) return 0;
        }
    }
    
    return 1;
}



//ham quay lui de kiem tra sudoku
int solve_sudoku(int arr[N][N], int hang, int cot){
    //kiem tra xem da den cuoi cua sudoku chua de ket thuc quay lui
    if(hang == N - 1 && cot == N) return 1;

    //xuong dong khi den cuoi dong
    if(cot == N){
        hang++;
        cot = 0;
    }

    //kiem tra xem vi tri hien tai da co gia tri > 0 chua
    if(arr[hang][cot] > 0) return solve_sudoku(arr, hang, cot + 1);

    //thu gan vao cac so tu 1 - 9 vao cac o cua sudoku
    for(int num = 1; num <= N; num++){
        if(is_safe(arr, hang, cot, num) == 1){
            arr[hang][cot] = num;
            if (solve_sudoku(arr, hang, cot + 1) == 1){
                return 1;
            }
        }
        arr[hang][cot] = 0;
    }
    return 0;
}

int main()
{
    srand(time(0));
	// 0 means unassigned cells
	int grid[N][N] = { 
					{ rand() % 9, rand() % 9, rand() % 9, rand() % 9, rand() % 9, rand() % 9, rand() % 9, rand() % 9, rand() % 9 },
					{ rand() % 9, rand() % 9, rand() % 9, rand() % 9, rand() % 9, rand() % 9, rand() % 9, rand() % 9, rand() % 9 },
					{ rand() % 9, rand() % 9, rand() % 9, rand() % 9, rand() % 9, rand() % 9, rand() % 9, rand() % 9, rand() % 9 },
					{ rand() % 9, rand() % 9, rand() % 9, rand() % 9, rand() % 9, rand() % 9, rand() % 9, rand() % 9, rand() % 9 },
					{ rand() % 9, rand() % 9, rand() % 9, rand() % 9, rand() % 9, rand() % 9, rand() % 9, rand() % 9, rand() % 9 },
					{ rand() % 9, rand() % 9, rand() % 9, rand() % 9, rand() % 9, rand() % 9, rand() % 9, rand() % 9, rand() % 9 },
					{ rand() % 9, rand() % 9, rand() % 9, rand() % 9, rand() % 9, rand() % 9, rand() % 9, rand() % 9, rand() % 9 },
					{ rand() % 9, rand() % 9, rand() % 9, rand() % 9, rand() % 9, rand() % 9, rand() % 9, rand() % 9, rand() % 9 },
					{ rand() % 9, rand() % 9, rand() % 9, rand() % 9, rand() % 9, rand() % 9, rand() % 9, rand() % 9, rand() % 9 } 
					};

    printf("De bai:\n");
    print(grid);
    printf("Dap an:\n");
	if (solve_sudoku(grid, 0, 0)==1)
		print(grid);
	else
		printf("No solution exists");
	return 0;
}