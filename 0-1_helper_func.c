#include "main.h"


/**
 * check_percent - writes a percent sign to standard output.
 *
 * @count_char: pointer to integer that keeps
 * track of number of characters written.
 */
void check_percent(int *count_char)
{
	my_putchar('%');
	(*count_char) += 1;
}

/**
 * handle_char - handles a single character conversion c
 *
 * @c: the conversion c character
 * @args: the va_list of arguments
 * @count: a pointer to the running count of printed characters
 * @width: the width of the field
 * @pre:  the precision of the field
 */
void handle_char(char c, va_list args, int *count, int width, int pre)
{
	char *str;
	int len;

	switch (c)
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

			if (pre >= 0 && pre < len)
				len = pre;

			if (width > len)
			{
				if (pre < 0)
					pre = len;

				if (width > pre)
				{
					for (int i = 0; i < width - len; i++)
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
			write(1, &c, 1);
			(*count)++;
			break;
		}
	}
}
