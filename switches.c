#include "main.h"
/*by div-styl and adilma53*/
/**
 * 
 * 
 * 
 * 
 * 
*/
void switches(char casevalue, va_list myarg, int *counter)
{
	switch (casevalue)
	{
	case 'c':
		check_char(myarg, counter);
		break;
	case 's':
		check_string(myarg, counter);
		break;
	case '%':
		my_putchar('%');
		(*counter)++;
		break;
	case 'd':
	case 'i':
        num_to_string(counter, va_arg(myarg, int));
        break;
	default:
		my_putchar(casevalue);
		(*counter)++;
		break;
	}
}
