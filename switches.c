#include "main.h"
/*by div-styl and adilma53*/
/**
 * handle_char - handles a single character conversion specifier
 *
 * @c: the conversion specifier character
 * @args: the va_list of arguments
 * @count: a pointer to the running count of printed characters
 */
void handle_char(char c, va_list args, int *count)
{
	switch (c)
	{
	case 'c':
	{
		char character = va_arg(args, int);

		write(1, &character, 1);
		(*count)++;
		break;
	}
	case 's':
	{
		char *s = va_arg(args, char *);

		if (s == NULL)
			s = "(null)";

		write(1, s, strlen(s));
		(*count) += strlen(s);
		break;
	}
	case 'd':
	case 'i':
	{
		int numbers = va_arg(args, int);
		char numbers_str[12];
		char *string_ptr;

		string_ptr = int_to_str(numbers, numbers_str);

		write(1, string_ptr, strlen(string_ptr));
		(*count) += strlen(string_ptr);
		break;
	}
	case '%':
	{
		write(1, "%", 1);
		(*count)++;
		break;
	}
	default:
	{
		write(1, "%", 1);
		write(1, &c, 1);
		(*count) += 2;
		break;
	}
	}
}
