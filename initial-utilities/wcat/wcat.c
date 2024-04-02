#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  if (argc < 2) {
    return 0;
  }
  char str[64];
  FILE *fp;
  for (int i = 1; i < argc; i++) {
    fp = fopen(argv[i], "r");
    if (fp == NULL) {
      printf("wcat: cannot open file\n");
      exit(1);
    }
    while (fgets(str, 64, fp) != NULL) {
      printf("%s", str);
    }
  }
  fclose(fp);

  return 0;
}
