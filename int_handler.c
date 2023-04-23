#include "main.h"


/**
 * int_handler - converts an integer to a string and writes it to stdout
 *
 * @num: the integer to be converted
 * @count_char: a pointer to the count of characters written
 *
 * Return: void
 */

void int_handler(int num, int *count_char)
{
	int digits = 0;
	int num_copy;
	int i;
	char numstr_buffer[12];

	if (num == 0)
	{
		write(1, "0", 1);
		(*count_char)++;
		return;
	}
	if (num == INT_MIN)
	{
		write(1, "-2147483648", 11);
		(*count_char) += 11;
		return;
	}
	if (num < 0)
	{
		write(1, "-", 1);
		(*count_char)++;
		num = -num;
	}
	num_copy = num;
	while (num_copy != 0)
	{
		num_copy /= 10;
		digits++;
	}

	for (i = digits - 1; i >= 0; i--)
	{
		numstr_buffer[i] = (num % 10) + '0';
		num /= 10;
	}
	numstr_buffer[digits] = '\0';
	write(1, numstr_buffer, _strlen(numstr_buffer));
	(*count_char) += _strlen(numstr_buffer);
}
