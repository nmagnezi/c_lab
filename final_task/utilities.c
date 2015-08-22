#include "constants.h"
#include "utilities.h"
#include <stdio.h>
#include <stdlib.h>

void print_usage() {
	char *help_msg = "An Assembler for given Assembli file(s).\n\
The program will produce .ob files and .ext .ent file(s) if needed.\n\
Note that the program does not include the linker and the loader stage.\n\n\
positional arguments:\n\
  FILENAME(s)			Name of .as file(s).\n\n\
optional arguments:\n\
  -h, --help            show this help message and exit\n\n";
	/* TODO: Find a nicer solution for this, code-style wise. */
    fprintf(stderr, "%s", help_msg);
    exit(EXIT_SUCCESS);
}

int check_all_true(int *array, int array_size) {
	int i;
	for (i = 0; i < array_size; ++i) {
		printf("%d\n", array[i]);
		if (array[i] != TRUE) {
			return FALSE;
		}
	}
	return TRUE;
}
