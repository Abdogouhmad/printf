#include "main.h"

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
		char ch = va_arg(args, int);

		write(1, &ch, 1);
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
		int num = va_arg(args, int);
		char num_str[12];
		char *str_ptr;

		str_ptr = int_to_str(num, num_str);

		write(1, str_ptr, strlen(str_ptr));
		(*count) += strlen(str_ptr);
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
