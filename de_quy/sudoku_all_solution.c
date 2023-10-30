#include <stdio.h>
#include <stdlib.h>

#define N 9

void print_solution (int arr[N][N]){
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
}

int is_safe(int arr[N][N], int hang, int cot, int num){
	//kiem tra xem cac so co cung mot hang hay khong
	for (int i  = 0; i <= 8; i++){
		if(arr[hang][i] == num) return 0;
	}

	//kiem tra xem cac so co cung mot cot hay khong
	for(int i = 0; i <= 8; i++){
		if(arr[i][cot] == num) return 0;
	}

	//kiem tra cac ma tran 3x3
	int hang_bat_dau = hang - hang % 3;
	int cot_bat_dau = cot - cot % 3;

	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			if(arr[i + hang_bat_dau][j + cot_bat_dau] == num) return 0;
		}
	}

	return 1;
}

int solve_sudoku(int arr[N][N], int hang, int cot){
	if (hang == N - 1 && cot == N)
		return 1;
	

	if (cot == N){
		hang++;
		cot = 0;
	}

	if(arr[hang][cot] > 0)
		return solve_sudoku(arr, hang, cot + 1);
	
	for(int num = 1; num <= N; num++){
		if (is_safe(arr, hang, cot, num) == 1){
			arr[hang][cot] = num;

			if(solve_sudoku(arr, hang, cot + 1) == 1) 
				return 1;
		}

		arr[hang][cot] = 0;
	}
	return 0;
}

int main()
{
	// 0 means unassigned cells
	int grid[N][N] = { 
					{ 0, 0, 0, 0, 0, 0, 0, 0, 0 },
					{ 0, 0, 0, 0, 0, 0, 0, 0, 0 },
					{ 0, 0, 0, 0, 7, 0, 0, 0, 0 },
					{ 0, 0, 0, 0, 0, 0, 0, 0, 0 },
					{ 0, 0, 0, 0, 0, 0, 0, 0, 0 },
					{ 0, 0, 0, 0, 0, 0, 0, 0, 0 },
					{ 0, 0, 0, 0, 0, 0, 0, 0, 0 },
					{ 0, 0, 0, 0, 0, 0, 0, 0, 0 },
					{ 0, 0, 0, 0, 0, 0, 0, 0, 0 } 
					};

	if (solve_sudoku(grid, 0, 0)==1)
		print_solution(grid);
	else
		printf("No solution exists");

	return 0;
}