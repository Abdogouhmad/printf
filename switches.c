#include "main.h"

/**
 *
 *
 *
 *
 *
*/
int switches(va_list myarg, int *counter)
{
	char character;

	character = va_arg(myarg, int);

	switch (character)
	{
	case 'c':
		check_char(myarg, counter);
		break;
	case 's':
		check_string(myarg, counter);
		break;
	case '%':
		my_putchar('%');
		counter++;
		break;
	case 'd':
		int_handler(myarg, counter);
		break;
	default:
		my_putchar(character);
		counter++;
		break;
	}
	return (counter);
}