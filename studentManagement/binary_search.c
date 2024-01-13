/*
 Bài tập Cho dãy gồm các số nguyên phân biệt
 a1, a2, …, an và một số nguyên Q. Hãy đến số bộ
 (i, j) sao cho 1 ≤ i < j ≤ n và ai + aj = Q
 • Cài đặt thuật toán trực tiếp
 • Cài đặt thuật toán cải tiến, sử dụng tìm kiếm nhị phân
 • Viết chương trình sinh ra dữ liệu ngẫu nhiên cho bài
 toán
 • So sánh về thời gian thực hiện với bộ dữ liệu có 102, 
 103, 105 and 106 phần tử
*/

#include <stdio.h>
#include <stdlib.h>

#define N 1000001

int a[N];
int n,Q;

//data structure for data input generation
int cand[N];
int sz;

void initSet(int _sz){
    for(int i = 1; i <= N; i++)cand[i] = i;
    for(int k = 1; k <= N; k++){
        int i = rand()%N;
        int j = rand()%N;
        int tmp = cand[i];cand[i] = cand[j]; cand[j] = tmp;
    }
    sz = _sz;
}

int selectAndRemone(){
    int i = rand()%sz;  int x =cand[i];
    cand[i] = cand[sz-1]; sz--;
    return x;
}

void genData(char* filename, int n, int Q){
    for(int i = 1; i <= n; i++) cand[i] = i;
    srand(time(NULL));
    FILE* f = fopen(filename, "w");
    fprint(f,"%d %d\n", n,Q); initSet(n);
    for(int i = 1; i <= n; i++){
        int x = selectAndRemone();
        fprintf(f,"%d", x);
    }
    fclose(f);
}

//end of data input generation

void input(char* filename){
    FILE* f = fopen(filename, "r");
    fscanf(f, "%d %d", &n, &Q);
    for(int i = 1; i <= n; i++)     fscanf(f,"%d", &a[i]);
    fclose(f);
}

void bruteForceSolve(){
    int cnt = 0;
    for(int i = 1;i < n; i++){
        for(int j = i+1; j <=n; j++){
            if(a[i] + a[j] == Q)
                cnt++;
        }
    }
    printf("Result = %d\n", cnt);
}

void swap(int i, int j){
    int temp = a[j];
    a[j] = a[i];
    a[i] = temp;
}

void heapify(int i, int n){
    int L = i*2;
    int R;
}