#include "../include/reader_csv.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void	read_csv(char *path_csv, char sep) {
	(void)sep;
	// Substitute the full file path
	// for the string file_path
	FILE *fp = fopen(path_csv, "r");
	char *wrds[40];
	if (!fp)
		printf("Can't open file\n");

	else {
		// Here we have taken size of
		// array 1024 you can modify it
		char buffer[1024];

		int row = 0;
		int column = 0;

		while (fgets(buffer, 1024, fp)) {
			column = 0;
			row++;

			// To avoid printing of column
			// names in file can be changed
			// according to need
			if (row == 1)
				continue;
			if (row == 10)
				break;

			// Splitting the data
			char *value = strtok(buffer, ", ");

			while (value) {
				// Column 1
				if (column == 0) {
					printf("[DATE]: ");
				}

				// Column 2
				if (column == 1) {
					printf("[TIME]: ");
				}

				// Column 3
				if (column == 2) {
					printf("[OPEN]: ");
				}

				// Column 4
				if (column == 3) {
					printf("[HIGH]: ");
				}

				// Column 5
				if (column == 4) {
					printf("[LOW]: ");
				}

				// Column 6
				if (column == 5) {
					printf("[CLOSE]: ");
				}

				// Column 7
				if (column == 6) {
					printf("[VOLUME]: ");
				}

				printf("%8s\t", value);
				wrds[column] = value;
				value = strtok(NULL, ", ");
				column++;
			}

			printf("\n");
		}

		// Close the file
		fclose(fp);
	}
}
