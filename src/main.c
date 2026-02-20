#define _GNU_SOURCE
#include <NexusC.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) {
  FILE *fp;

  fp = fopen("data/XAU_1m_data.csv", "r");
  if (!fp)
    return (1);

  read_csv(fp);

  fclose(fp);
  return (0);
}
