
#include "main.h"

/**
 * main - ...........
 *
 * @void: ........
 *
 * Return: ....
 *
 */

int main(void)
{

	int len = 0;
	int len2 = 0;
	unsigned int ui;
	ui = (unsigned int)INT_MAX + 1024;
	_printf("Character:[%c]\n", 'H');
	printf("Character:[%c]\n", 'H');

	_printf("String:[%s]\n", "I am a string !");
	printf("String:[%s]\n", "I am a string !");


	len = _printf("Percent:[%%]\n");
	len2 = printf("Percent:[%%]\n");


	printf("Len:[%d]\n", len);
	printf("Len2:[%d]\n", len2);

	_printf("%d\n", -2147483648);
	_printf("%b\n", 98);


	_printf("Unsigned hexadecimal:[%x, %X]\n", ui, ui);
   _printf("Unsigned octal:[%o]\n", ui);

	_printf("Unsigned:[%u]\n", ui);
	 _printf("%S\n", "Best\nSchool");
	
	return (0);
}
