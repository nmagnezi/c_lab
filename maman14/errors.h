#ifndef _ERRORS_H
#define _ERRORS_H

#define InsufficientNumOfArgumentsError "You must provide a least one filename.\n Use --help for usage information"

/**
 * Raise en error to stderr and exit.
 */
void raise_error(const char* err);

#endif
