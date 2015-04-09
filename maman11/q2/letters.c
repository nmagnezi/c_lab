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
		if isdigit(input_char) continue;

		switch(input_char)
		{
		case WHITESPACE:
			break;

		case END_OF_SENTENCE:
			first_char_in_sentence = 1;
			break;

		case NEW_LINE_CHAR:
			first_char_in_sentence = 1;
			break;

		case QUOTE_CHAR:
			if (first_quote_char)
			{
				print_in_quote = 1;
				first_quote_char = 0;
			}
			else
			{
				print_in_quote = 0;
				first_quote_char = 1;
			}
		}

		if ((input_char == END_OF_SENTENCE) || (input_char == WHITESPACE) || (input_char == QUOTE_CHAR))
		{
			printf("%c", input_char);
		}
		else if (input_char == NEW_LINE_CHAR)
		{
			printf("\n\n");
		}
		else if ((print_in_quote) || (first_char_in_sentence))
		{
			printf("%c",  toupper(input_char));
			if (first_char_in_sentence)
			{
				first_char_in_sentence = 0;
			}
		}
		else
		{
			printf("%c", tolower(input_char));
		}

	}
	return 0;
}
