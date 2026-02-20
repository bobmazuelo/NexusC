#include "../include/reader_csv.h"
#include <stdio.h>
#include <stdlib.h>

void	read_csv(char *path_csv, char sep = ',')
{
	FILE		*fp;
	char		*line = NULL;
	size_t		len = 0;
	unsigned int	i = 0;

	fp = fopen(path_csv, "r");
	if (!fp) return;

	while (getline(&line, &len, fp) != -1) i++;

	printf("[SIZE TOTAL FILE]: %u\n", i);

	free(line);
	fclose(fp);
}
