#include <stdio.h>

int MaxSubseqSum1(int a[], int n) {
  int i, j, k;
  int ThisSum, MaxSum = 0;
  for (i = 0; i < n; i++) {
    for (j = i; j < n; j++) {
      ThisSum = 0;
      for (k = 0; k <= j; k++) {
        ThisSum += a[k];
        if (ThisSum > MaxSum)
          MaxSum = ThisSum;
      }
    }
  }
  return MaxSum;
}

int MaxSubseqSum2(int a[], int n) {
  int i, j;
  int ThisSum, MaxSum = 0;
  for (i = 0; i < n; i++) {
    ThisSum = 0;
    for (j = i; j < n; j++) {
      ThisSum += a[k];
      if (ThisSum > MaxSum)
        MaxSum = ThisSum;
    }
  }
  return MaxSum;
}

int main() { return 0; }
