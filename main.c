
#include "main.h"



/**
 * main - ..
 *
 * @void: ..
 *
 * Return: ..
 */

int main()
{
	int count = 0, large_num = 1234567890, i;

	count = _printf("Hello, world!\n");
	printf("Number of characters printed: %d\n\n", count);
	count = _printf("The first five even numbers are: %d %d %d %d %d\n", 2, 4, 6, 8, 10);
	printf("Number of characters printed: %d\n\n", count);
	count = _printf("The square root of 2 is approximately %f\n", 1.41421356);
	printf("Number of characters printed: %d\n\n", count);
	printf("Printing 10000 numbers:\n");
	for (i = 0; i < 10000; i++)
		count = _printf("%d ", i);
	printf("\nNumber of characters printed: %d\n\n", count);
	count = _printf("Large number: %d\n", large_num);
	printf("Number of characters printed: %d\n\n", count);
	count = _printf("Hello, world!\n");
	printf("Number of characters printed: %d\n\n", count);
	count = _printf("The first five even numbers are: %d %d %d %d %d\n", 2, 4, 6, 8, 10);
	printf("Number of characters printed: %d\n\n", count);
	count = _printf("The square root of 2 is approximately %f\n", 1.41421356);
	printf("Number of characters printed: %d\n\n", count);
	count = _printf("This is a very long string that should test whether our printf function can handle very long strings without any issues. I really hope it can, because otherwise we might be in trouble!\n");
	printf("Number of characters printed: %d\n\n", count);
	count = _printf("%d\n", 1234567890);
	printf("Number of characters printed: %d\n\n", count);
	count = _printf("%d\n", -1234567890);
	printf("Number of characters printed: %d\n\n", count);
	_printf("%d\n", -2147483648);
	_printf("%d\n", 2147483647);
	return (0);
}
