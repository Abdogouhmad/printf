#include "main.h"
/*by div-styl and adilma53*/
/**
 * num_to_string -transform string to number
 * @num:number that we would convert to string
 * @count_char: the result into string
 * Return: void
*/
void num_to_string(int num, int *count_char)
{
	int digits = 0;

	if (num == 0)
	{
		write(1, "0", 1);
		(*count_char)++;
		return;
	}

	if (num < 0)
	{
		write(1, "-", 1);
		(*count_char)++;
		num = -num;
	}
	int num_copy = num;

	while (num_copy != 0)
	{
		num_copy /= 10;
		digits++;
	}

	char numstr_buffer[digits + 1];

	for (int i = digits - 1; i >= 0; i--)
	{
		numstr_buffer[i] = (num % 10) + '0';
		num /= 10;
	}

	numstr_buffer[digits] = '\0';

	write(1, numstr_buffer, strlen(numstr_buffer));
	(*count_char) += strlen(numstr_buffer);
}
