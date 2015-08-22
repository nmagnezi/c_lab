
#include "assembler.h"
#include "constants.h"
#include "errors.h"
#include "filehandler.h"

int assemble_file(char* file_name) {
	int file_opened = FALSE;
	file_opened = open_file(file_name);
	if (!file_opened) {
		return FALSE;	}

/* code */

	return TRUE;
}
