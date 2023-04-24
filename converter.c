#include "main.h"
/*by div-styl && Adilma53*/
/**
 * number_to_binary -converts a number to binary
 * @num: number to be converted
 * Return: void
 */
void number_to_binary(unsigned int num)
{
	char cara;

	if (num == 0)
	{
		write(1, "0", 1);
		return;
	}

	if (num > 1)
	{
		number_to_binary(num / 2);
	}
	if (num % 2 == 0)
	cara = '0';
	else
	cara = '1';
	write(1, &cara, 1);
}
