#include "../include/reader_csv.h"
#include <stdio.h>

void read_csv(FILE *fp) {
  char *line = NULL;
  size_t len = 0;
  unsigned int i = 0;

  while (getline(&line, &len, fp) != -1) {
    i++;
  }

  printf("[SIZE TOTAL FILE]: %u\n", i);
}