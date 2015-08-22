#include "constants.h"
#include "errors.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_error(char *err) {
	fprintf(stderr, "Error: %s\n", err);
}

void raise_fatal_error(char* err) {
	print_error(err);
	exit(EXIT_FAILURE);
}

int raise_error(char* err) {
	print_error(err);
	return EXIT_FAILURE;
}

void raise_error_with_param(char *err, char *param) {
    char *err_with_param = malloc(strlen(err)+strlen(param)+1);
    if (!err_with_param) {
		raise_fatal_error(CannotAllocateMemoryError);
	}
    strcpy(err_with_param, err);
    strcat(err_with_param, param);
    raise_error(err_with_param);
}
