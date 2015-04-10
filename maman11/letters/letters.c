/*
maman11_q2 - letters.c
* Description:
The Program gets chars from standard input and prints them with the following modifications:
1. At the beginning of each sentence, if the first char is a letter, it is printed in upper case.
2. Quoted expressions printed in upper case.
3. Rest of the chars printed in lower case.
4. Digits are Omitted.
5. Blank line should be printed between each 2 lines.
*/

#include <stdio.h>
#include <ctype.h>

#define NEW_LINE_CHAR '\n'
#define QUOTE_CHAR '"'
#define END_OF_SENTENCE '.'
#define WHITESPACE ' '

int main()
{
	char input_char;
	int first_char_in_sentence = 1;
	int print_in_quote = 0;
	int first_quote_char = 1;

	while ((input_char = getchar()) != EOF)
	{
		if isdigit(input_char) continue; /* no processing needed for digits */

		switch(input_char)
		{
		case WHITESPACE: /* avoid changing upper case or lower case flags for whitespace char */
			break;

		case END_OF_SENTENCE: /* next letter should be upper case */
			first_char_in_sentence = 1;
			break;

		case NEW_LINE_CHAR: /* next letter should be upper case */
			first_char_in_sentence = 1;
			break;

		case QUOTE_CHAR: /* handles quoted expression */
			if (first_quote_char) /* opens quoted expression */
			{
				print_in_quote = 1;
				first_quote_char = 0;
			}
			else /* ends quoted expression */
			{
				print_in_quote = 0;
				first_quote_char = 1;
			}
		}

		if ((input_char == END_OF_SENTENCE) || (input_char == WHITESPACE) || (input_char == QUOTE_CHAR))
		{   /* handles chars that should be printed without changing flags */
			printf("%c", input_char);
		}
		else if (input_char == NEW_LINE_CHAR)
		{   /* handles the double newline print */
			printf("\n\n");
		}
		else if ((print_in_quote) || (first_char_in_sentence))
		{	/* handles all cases of upper case prints*/
			printf("%c",  toupper(input_char));
			if (first_char_in_sentence)
			{	/* if upper case print is due to a first char in sentence, Disable it for next char */
				first_char_in_sentence = 0;
			}
		}
		else
		{   /* other cases are lower case prints */
			printf("%c", tolower(input_char));
		}

	}
	return 0;
}
