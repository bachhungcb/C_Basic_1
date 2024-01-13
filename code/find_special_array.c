#include <stdio.h>

#include <stdlib.h>

#include <math.h>N

#include <limits.h>

#define MAX 10000

int main() {
  int n;
  printf("Nhap vao so phan tu cua mang: \n");
  scanf("%d", & n);
  double A[MAX];
  double sum = 0;
  double average, min_diff;

  printf("nhap vao cac gia tri trong mang:\n");

  for (int i = 0; i < n; i++) {
    printf("gia tri thu %d: ", i + 1);
    scanf("%lf", & A[i]);
    sum = sum + A[i];
  }

  for (int i = 0; i < n; i++) {
    printf("%f\n", A[i]);

  }

  average = sum / n;
  int min_index = 0;
  min_diff = fabs(A[0] - average);

  for (int i = 0; i < n; i++) {
    double diff = fabs(A[i] - average);
    if (diff <= min_diff) {
      min_diff = diff;
      min_index = i;
    }
  }

  printf("Phan tu can tim la: %f", A[min_index]);
  return 0;
}
