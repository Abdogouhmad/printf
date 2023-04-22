#include "main.h"
/*by div-styl and adilma53*/
/**
 * num_to_string -transform string to number
 * @num:
 * @count_char:
 * Return: void
*/
void num_to_string(int num, int *count_char)
{
	int digits = 0;

	// Check if the number is 0
	if (num == 0)
	{
		write(1, "0", 1);
		(*count_char)++;
		return;
	}

	// Check if the number is negative
	if (num < 0)
	{
		write(1, "-", 1);
		(*count_char)++;
		num = -num;
	}

	// Find the number of digits in the number
	int num_copy = num;
	while (num_copy != 0)
	{
		num_copy /= 10;
		digits++;
	}

	// declare buffer
	char numstr_buffer[digits + 1];

	for (int i = digits - 1; i >= 0; i--)
	{
		numstr_buffer[i] = (num % 10) + '0';
		num /= 10;
	}

	//give it the null character
	numstr_buffer[digits] = '\0';

	// Write the string to the console
	write(1, numstr_buffer, strlen(numstr_buffer));
	(*count_char) += strlen(numstr_buffer);
}


