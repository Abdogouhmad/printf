#include "main.h"
/*by div-styl and adilma53*/
/**
 * switches - checks for valid arguments
 * @casevalue: argument passed to function
 * @myarg: argument passed to function
 * @counter: counter to count characters printed
 * Return: void
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