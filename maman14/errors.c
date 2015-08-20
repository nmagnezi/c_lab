#include "constants.h"
#include "errors.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void raise_error(char* err) {
	fprintf(stderr, "Error: %s\n", err);
	exit(EXIT_FAILURE);
}

void raise_error_with_param(char *err, char *param) {
    char *err_with_param = malloc(strlen(err)+strlen(param)+1);
    if (!err_with_param) {
		raise_error(CannotAllocateMemoryError);
	}
    strcpy(err_with_param, err);
    strcat(err_with_param, param);
    raise_error(err_with_param);
}
