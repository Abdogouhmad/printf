#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>
#include <string.h>


/**
 * handle_char - handles a single character conversion specifier
 *
 * @specifier: the conversion specifier character
 * @args: the va_list of arguments
 * @count: a pointer to the running count of printed characters
 * @width: the width specifier (optional)
 * @precision: the precision specifier (optional)
 */
void handle_char(char specifier, va_list args, int *count, int width, int precision)
{
	char *str;
	int len, i = 0;

	switch (specifier)
	{
		case 'c':
		{
			int c = va_arg(args, int);

			write(1, &c, 1);
			(*count)++;
			break;
		}
		case 's':
		{
			str = va_arg(args, char *);

			if (str == NULL)
				str = "(null)";

			len = strlen(str);

			if (precision >= 0 && precision < len)
				len = precision;

			if (width > len)
			{
				if (precision < 0)
					precision = len;

				if (width > precision)
				{
					for (i = 0; i < width - len; i++)
					{
						write(1, " ", 1);
						(*count)++;
					}
				}
			}

			write(1, str, len);
			(*count) += len;
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
			write(1, &specifier, 1);
			(*count)++;
			break;
		}
	}
}

/**
 * _printf - prints formatted output to a stream
 *
 * @stream: the output stream
 * @format: a string containing format specifiers that control the output.
 *          Supported format specifiers are %c, %s, and %%.
 * @...: optional arguments to be printed according to the format specifiers.
 *
 * Return: the number of characters printed, or -1 on error.
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
