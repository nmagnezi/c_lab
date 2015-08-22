#include "constants.h"
#include "errors.h"
#include "filehandler.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE* asm_file;

int open_file(char* filename) {
    char *filename_with_suffix;

    /* glue the filename with it's suffix */
    filename_with_suffix = malloc(strlen(filename)+strlen(ASM_FILE_SUFFIX)+1);
	if (!filename_with_suffix) {
		raise_fatal_error(CannotAllocateMemoryError);
	}
    strcpy(filename_with_suffix, filename);
    strcat(filename_with_suffix, ASM_FILE_SUFFIX);

    /* TODO: remove this debug */
    printf("%s\n", filename_with_suffix);

    asm_file = fopen(filename_with_suffix, "r");
	if (!asm_file) {
		raise_error_with_param(CannotOpenFileError, filename_with_suffix);
        free(filename_with_suffix);
        return FALSE;
	}
	free(filename_with_suffix);
    return TRUE;
}
