#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>
#include <string.h>


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
		char c = va_arg(args, int);

		if (c == '\n')
			write(1, "\n", 1);
		else
			write(1, &c, 1);
		(*count)++;
		break;
	}
	case 's':
	{
		char *s = va_arg(args, char *);

		if (s == NULL)
			write(1, "(null)", 6);
		else
			write(1, s, strlen(s));
		(*count) += strlen(s);
		break;
	}
	case '%':
	{
		write(1, "%", 1);
		(*count)++;
		break;
	}
	case '\n':
		break;

	default:
		break;
	}
}

/**
 * _printf - prints formatted output to standard output.
 *
 * @format: a string containing format specifiers that control the output.
 *          Supported format specifiers are %c, %s, and %%.
 *          Any other characters are printed as-is.
 * @...: optional arguments to be printed according to the format specifiers.
 *
 * Return: .....
 * or -1 if an error occurs.
 */
int _printf(const char *format, ...)
{
	int count = 0, i;
	va_list args;

	va_start(args, format);

	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);
	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
			handle_char(format[++i], args, &count);
		else
		{
			write(1, &format[i], 1);
			count++;
		}
	}
	va_end(args);
	if (format[i - 1] == '%')
	{
		write(2, "error: format string ends with '%'\n", 35);
		return (-1);
	}
	return (count);
}
