#include "printb.h"
#include <stdio.h>
extern const int N, M;
void printb(char a[][M]) {
  int i, j;
  printf("   a b c d e f g h\n");
  for (i = 0; i < N; i++) {
    printf("\n%d ", i + 1);
    for (j = 0; j < M; j++) {
      printf("%2c", a[i][j]);
    }
  }
  printf("\n");
}
