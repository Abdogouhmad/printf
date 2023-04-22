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
 * (excluding the terminating null byte).
 */

int _printf(const char *format, ...)
{
	int i;
	int count_char = 0;
	va_list myarg;

	if (format == NULL)
		return (-1);
	va_start(myarg, format);
	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			switch (format[i + 1])
			{
			case 'c':
				check_char(myarg, &count_char);
				i++;
				break;
			case 's':
				check_string(myarg, &count_char);
				i++;
				break;
			case '%':
				my_putchar('%');
				count_char++;
				i++;
				break;
			default:
				my_putchar(format[i + 1]);
				count_char++;
				break;
			}
		}
		else if (format[i] != '%')
		{
			my_putchar(format[i]);
			count_char++;
		}
	}
	va_end(myarg);
	return (count_char);
}
