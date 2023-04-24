#include "main.h"
/*by div-styl && Adilma53*/
/**
 * number_to_binary -converts a number to binary
 * @num: number to be converted
 * Return: void
 */
void number_to_binary(unsigned int num)
{
	if (num > 1)
		number_to_binary(num / 2);

	write(1, (num % 2) ? "1" : "0", 1);
}
