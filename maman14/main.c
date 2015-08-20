#include "errors.h"
#include "constants.h"
#include "utils.h"
#include <stdlib.h>
#include <string.h>

int main(int argc,char *argv[]) {
	/* The Program was executed with no files to parse. */
	if (argc < 2) {
		raise_error(InsufficientNumOfArgumentsError);
	}

	/* Got print help flags. */
	if((!strcmp(argv[1], USAGE_FLAG_A) || !strcmp(argv[1], USAGE_FLAG_B))) {
		print_usage();
	}




    exit(EXIT_SUCCESS);
}
