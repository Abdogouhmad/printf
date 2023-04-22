#include "main.h"
/*by div-styl and adilma53*/
/**
 * 
 * 
 * 
 * 
 * 
*/
int switches(char casevalue, va_list myarg, int *counter)
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
				counter++;
				break;
			case 'd':
				num_to_string(myarg, counter);
				break;
			case 'i':
				num_to_string(myarg, counter);
				break;
			default:
				my_putchar(casevalue);
				counter++;
				break;
            }
            return (counter);
}