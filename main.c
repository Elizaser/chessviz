
#include <stdio.h>
#include <string.h>
const int N = 8;

int main(int argc, char *argv[]) {
  char filename[10];
  FILE *file;
  int i, j;
  char a[N + 1][N + 1];

  if (argc > 1) {
    strcpy(filename, argv[1]);
  }

  file = fopen(filename, "r");
  if (!file)
    printf("Error\n");

  fread(a, sizeof(a), 1, file);

  fclose(file);
  for (i = 0; i < N + 1; i++) {
    for (j = 0; j < N + 1; j++) {
      printf("%c", a[i][j]);
    }
  }
  return 0;
}