#include "constants.h"
#include "errors.h"
#include <stdio.h>
#include <stdlib.h>

void raise_error(const char* err)
{
	fprintf(stderr, "Error: %s\n", err);
	exit(EXIT_FAILURE);
}
