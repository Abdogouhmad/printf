#include "main.h"

/**
 * num_to_string - transform number to string
 * @count_char: the result into string
 * @num: number that we would convert to string
 *
 * Return: void
 */
void num_to_string(int *count_char, int num)
{
	int digits = 0, num_copy, i;
	char numstr_buffer[MAX_DIGITS + 1];

if (num == 0)
{
	write(1, "0", 1);
	(*count_char)++;
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

write(1, numstr_buffer, strlen(numstr_buffer));
(*count_char) += strlen(numstr_buffer);
}

/**
 * 
 * 
 * 
 * 
*/
void check_percent(int *count_char)
{
    my_putchar('%');
    (*count_char)++;
}
