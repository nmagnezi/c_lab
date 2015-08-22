#ifndef _ERRORS_H
#define _ERRORS_H

#define InsufficientNumOfArgumentsError "You must provide a least one filename.\n Use --help for usage information"
#define CannotAllocateMemoryError "Failed to allocate memory.\n"
#define CannotOpenFileError "Cannot open file: "
#define NotAllFilesAssembledError "Not All files were successfully assembled.\n"

void print_error(char *err);

void raise_fatal_error(char* err);

int raise_error(char* err);

void raise_error_with_param(char *err, char *param);

#endif
