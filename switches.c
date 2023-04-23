#include "main.h"

/**
<<<<<<< HEAD
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
=======
 * switches - checks for valid arguments
 * @c: argument passed to function
 * @myarg: argument passed to function
 * @counter: counter to count characters printed
 * Return: void
*/
void switches(char c, va_list myarg, int *counter)
{
switch (c)
{
>>>>>>> a5ddaf89e94b6be1e35a9f16032da5363aaec997
	case 'c':
		check_char(myarg, counter);
		break;
	case 's':
		check_string(myarg, counter);
		break;
	case '%':
<<<<<<< HEAD
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
=======
		check_percent(counter);
		break;
	case 'd':
		num_to_string(counter, va_arg(myarg, int));
		break;
	case 'i':
		num_to_string(counter, va_arg(myarg, int));
		break;
	default:
		my_putchar(c);
		(*counter)++;
		break;
}
}
>>>>>>> a5ddaf89e94b6be1e35a9f16032da5363aaec997
