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
 * num_len - returns the length of an integer
 *
 * @num: the integer to measure
 * Return: the length of the integer
 */
int num_len(int num)
{
	int len = 0;

	if (num == 0)
		return (1);

	while (num != 0)
	{
		num /= 10;
		len++;
	}

	return (len);
}

/**
 * int_to_str - converts an integer to a string
 *
 * @num: the integer to convert
 * @str: a buffer to store the resulting string
 * Return: a pointer to the resulting string
 */
char *int_to_str(int num, char *str)
{
	int len = num_len(num);
	int i;

	if (num < 0)
	{
		*str++ = '-';
		num = -num;
		len++;
	}

	str += len;
	*str-- = '\0';

	for (i = 0; i < len; i++)
	{
		*str-- = num % 10 + '0';
		num /= 10;
	}

	return (str + 1);
}
