#include "main.h"

/**
 * my_strlen - calculate length of a string.
 *
 * @str: pointer to the string.
 *
 * Return: length of a string (excludes null charachter).
 */
int my_strlen(const char *str)
{
	int length = 0;
	int i;

	for (int i = 0; str[i] != '\0'; ++i)
		length++;

	return (length);
}


/**
 * my_putchar - write a single character to standard output.
 *
 * @c: the character to be written.
 */
void my_putchar(const char c)
{
	write(1, &c, 1);
}

/**
 * print_string - writes a string to standard output.
 *
 * @string: pointer to the string.
 */
void print_string(const char *string)
{
	int len = my_strlen(string);
	write(1, string, len);
}


/**
 * check_char - writes a single character to standard output.
 *
 * @myarg: character to be written.
 * @count_char: pointer to integer that keeps track of number of characters written.
 */
void check_char(va_list myarg, int *count_char)
{
	my_putchar((char)va_arg(myarg, int));
	(*count_char) += 1;
}


/**
 * check_string - writes a string to standard output.
 *
 * @myarg: the string to be written.
 * @count_char: pointer to integer that keeps track of number of characters written.
 */
void check_string(va_list myarg, int *count_char)
{
	char *str = va_arg(myarg, char *);
	print_string(str);
	(*count_char) += my_strlen(str);
}