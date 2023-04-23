#include "main.h"


/**
 * switches - .......
 *
 * @c: .............
 * @myarg: .......
 * @counter: ..........
 *
 * Return: ...........
 */
void switches(char c, va_list myarg, int *counter)
{
	switch (c)
	{
	case 'c':
		check_char(myarg, counter);
		break;
	case 's':
		check_string(myarg, counter);
		break;
	case '%':
		my_putchar(c);
		(*counter)++;
		break;
	default:
		my_putchar(c);
		(*counter)++;
		break;
	}
}
