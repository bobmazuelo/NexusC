#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	FILE		*fp;
	char		*line = NULL;
	size_t		len = 0;
	unsigned int	i = 0;

	fp = fopen("data/XAU_1m_data.csv", "r");
	if (!fp)
		return (1);

	while (getline(&line, &len, fp) != -1)
	{
		i++;
	}

	printf("[SIZE TOTAL FILE]: %u\n", i);

	fclose(fp);
	if (line) free(line);
	return (0);
}
