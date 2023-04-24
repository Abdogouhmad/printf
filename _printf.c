#include  "main.h"


/**
 * _printf - prints formatted output to standard output.
 *
 * @format: a string containing format specifiers that control the output.
 *          Supported format specifiers are %c, %s, and %%.
 *          Any other characters are printed as-is.
 * @...: optional arguments to be printed according to the format specifiers.
 *@stream:  the stream to print to.
 * Return: .....
 * or -1 if an error occurs.
 */

int _printf(FILE *stream, const char *format, ...)
{
	int count = 0, i, width = 0, precision = -1;
	va_list args;

	if (!format)
		return (-1);

	va_start(args, format);

	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			i++;

			if (format[i] == '\0')
				return (-1);

			if (format[i] == '-')
			{
				i++;
				width = -1;
			}

			while (format[i] >= '0' && format[i] <= '9')
			{
				width = width * 10 + format[i] - '0';
				i++;
			}

			if (format[i] == '.')
			{
				i++;
				precision = 0;

				while (format[i] >= '0' && format[i] <= '9')
				{
					precision = precision * 10 + format[i] - '0';
					i++;
				}
			}

			if (width < 0)
			{
				width = -width;
				precision = -1;
			}

			handle_char(format[i], args, &count, width, precision);
			width = 0;
			precision = -1;
		}
		else
		{
			write(fileno(stream), &format[i], 1);
			count++;
		}
	}

	va_end(args);

	return (count);
}
