#include "assembler.h"
#include "errors.h"
#include "constants.h"
#include "utilities.h"

#include "stdio.h"

#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
	/* The Program was executed with no files to parse. */
	if (argc < 2) {
		raise_error(InsufficientNumOfArgumentsError);
	}

	/* Got print help flags. */
	if((!strcmp(argv[1], USAGE_FLAG_A) || !strcmp(argv[1], USAGE_FLAG_B))) {
		print_usage();
	}

	/* Assemble files */
    do {
    	printf("debug: %s\n", argv[argc - 1]); /* TODO: Remove this */
    	assemble_file(argv[argc - 1]);
       	argc--;
    }while(argc > 1);

    exit(EXIT_SUCCESS);
}
