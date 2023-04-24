#include "main.h"


/**
 * check_percent - writes a percent sign to standard output.
 *
 * @count_char: pointer to integer that keeps
 * track of number of characters written.
 */
void check_percent(int *count_char)
{
	my_putchar('%');
	(*count_char) += 1;
}

