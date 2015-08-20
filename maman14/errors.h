#ifndef _ERRORS_H
#define _ERRORS_H

#define InsufficientNumOfArgumentsError "You must provide a least one filename.\n Use --help for usage information"
#define CannotAllocateMemoryError "Failed to allocate memory."
#define CannotOpenFileError "Cannot open file: "

/**
 * Raise en error to stderr and exit.
 */
void raise_error(char* err);

void raise_error_with_param(char *err, char *param);

#endif
