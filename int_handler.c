#include "main.h"

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
	if (num < 0)
	{
		write(1, "-2147483648", 10);
		(*count_char) += 10;
		return;
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
	write(1, numstr_buffer, strlen(numstr_buffer));
	(*count_char) += strlen(numstr_buffer);
}