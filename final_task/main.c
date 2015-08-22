#include "main.h"

int main(int argc, char *argv[]) {
	int amount_of_files = argc-1;
	int files_assembled = FALSE;
	int file_assembled = FALSE;

	/* The Program was executed with no files to parse. */
	if (argc < 2) {
		raise_fatal_error(InsufficientNumOfArgumentsError);
	}

	/* Got print help flags. */
	if((!strcmp(argv[1], USAGE_FLAG_A) || !strcmp(argv[1], USAGE_FLAG_B))) {
		print_usage();
	}

	/* Assemble files */
    do {
    	printf("debug: %s\n", argv[argc - 1]); /* TODO: Remove this */
    	file_assembled = assemble_file(argv[argc - 1]);
    	if (file_assembled) {
    		files_assembled++;
    	}
       	argc--;
    }while(argc > 1);

	if (files_assembled < amount_of_files) {
		raise_fatal_error(NotAllFilesAssembledError);
	}
	else {
		exit(EXIT_SUCCESS);
	}

}
