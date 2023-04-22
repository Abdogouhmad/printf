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
	int i = 0;
	int count_char = 0;
	va_list myarg;

	if (format == NULL)
		return (-1);
	va_start(myarg, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			switch (format[i])
			{
			case 'c':
				check_char(myarg, &count_char);
				break;
			case 's':
				check_string(myarg, &count_char);
				break;
			case '%':
				my_putchar('%');
				count_char++;
				break;
			default:
				my_putchar(format[i]);
				count_char++;
				break;
			}
		}
		else
		{
			my_putchar(format[i]);
			count_char++;
		}
		i++;
	}
	va_end(myarg);
	return (count_char - 1);
}