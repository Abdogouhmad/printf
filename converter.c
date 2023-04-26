#include "main.h"
/*by div-styl && Adilma53*/
/**
 * number_to_binary -converts a number to binary
 * @num: number to be converted
 * Return: void
 */
int number_to_binary(unsigned int num)
{
	char digit;
	int count;

	if (num == 0)
	{
		write(1, "0", 1);
		return (1);
	}

	count = 0;

	if (num > 1)
		count += number_to_binary(num / 2);

	digit = (num % 2) ? '1' : '0';
	write(1, &digit, 1);
	count++;

	return (count);
}
/**
 * print_hex - prints a number in hex
 * @num: number to be printed
 * Return: void
*/
void print_hex(unsigned int num)
{
	const char hx_dg[] = "0123456789ABCDEF";
	char bffr[2];
	int index = 0, rmd, i;

	while (num != 0)
	{
		rmd = num % 16;
		bffr[index++] = hx_dg[rmd];
		num /= 16;
	}

	if (index == 1)
	{
		my_putchar('0');
	}

	for (i = index - 1; i >= 0; i--)
	{
		if (bffr[i] == '0' && i == index - 1)
			my_putchar('0');
		else if (bffr[i] <= 0xF)
		{
			my_putchar('0');
			my_putchar(bffr[i]);
		}
		else
			my_putchar(bffr[i]);
	}
}
