
#include "main.h"
#define MAX_BUFFER_SIZE 64

/**
 * hex_octa_binary - converts a number to a hex
 *
 * @num: number to be converted
 * @base: number convered
 *
 * Return: ....
 */

int hex_octa_binary(unsigned int num, char base)
{
	char hex_lower[] = "0123456789abcdef";
	char hex_upper[] = "0123456789ABCDEF";
	char buffer[MAX_BUFFER_SIZE];
	int remainder, i = 0, j;

	if (num == 0)
	{
		my_putchar('0');
		return (1);
	}
	if (base == 'x')
	{
		while (num != 0)
		{
			remainder = num % 16;
			buffer[i++] = hex_lower[remainder];
			num /= 16;
		}
	}
	else if (base == 'X')
	{
		while (num != 0)
		{
			remainder = num % 16;
			buffer[i++] = hex_upper[remainder];
			num /= 16;
		}
	}
	else if (base == 'o')
	{
		while (num != 0)
		{
			remainder = num % 8;
			buffer[i++] = remainder + '0';
			num /= 8;
		}
	}
	for (j = i - 1; j >= 0; j--)
		my_putchar(buffer[j]);
	return (i);
}

/**
 * uint_handler - .....
 *
 * @num: ....
 *
 * Return: ....
 */
int uint_handler(unsigned int num)
{
	int digits = 0;
	unsigned int num_copy;
	int i;
	char numstr_buffer[11];

	if (num == 0)
	{
		write(1, "0", 1);
		return (1);
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
	write(1, numstr_buffer, digits);

	return (digits);
}
