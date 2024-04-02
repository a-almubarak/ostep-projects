#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void wgrep(FILE *fp, char *term) {
  size_t buffer_size = 1024;
  char *line = malloc(sizeof(char) * buffer_size);
  while (getline(&line, &buffer_size, fp) != -1) {
    if (strstr(line, term) != NULL) {
      printf("%s", line);
    }
  }
  fclose(fp);
}
int main(int argc, char *argv[]) {
  if (argc < 2) {
    printf("wgrep: searchterm [file ...]\n");
    exit(1);
  }
  char *term = argv[1];
  FILE *fp;
  if (argc == 2) {
    fp = stdin;
    wgrep(fp, term);
    return 0;
  }
  for (int i = 2; i < argc; i++) {
    fp = fopen(argv[i], "r");
    if (fp == NULL) {
      printf("wgrep: cannot open file\n");
      exit(1);
    }
    wgrep(fp, term);
  }

  return 0;
}
