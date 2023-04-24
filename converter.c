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
