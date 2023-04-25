#include "main.h"



/**
 * _printf - prints formatted output to standard output.
 *
 * @format: a string containing format specifiers that control the output.
 *          Supported format specifiers are %c, %s, and %%.
 *          Any other characters are printed as-is.
 * @...: optional arguments to be printed according to the format specifiers.
 *
 * Return: the number of characters printed
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
		{
			if (format[++i] == 'o' || format[++i] == 'x' || format[++i] == 'X')
			{
				unsigned int num = (va_arg(args, unsigned int));

				count += hex_octa_binary(num, format[++i]);
			}
			else if (format[++i] == 'u')
			{
				unsigned int num = (va_arg(args, unsigned int));

				count += uint_handler(num);
			}
			else
				handle_char(format[++i], args, &count);
		}
		else
		{
			write(1, &format[i], 1);
			count++;
		}
	}

	va_end(args);
	return (count);
}
