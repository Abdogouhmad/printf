#include "main.h"



/**
 * _printf - prints formatted output to standard output.
 *
 * @format: a string containing format specifiers that control the output.
 *          Supported format specifiers are %c, %s, and %%.
 *          Any other characters are printed as-is.
 * @...: optional arguments to be printed according to the format specifiers.
 *
 * Return: the number of characters printed (excluding the terminating null byte).
 */
int _printf(const char *format, ...)
{
    int count = 0;
    va_list myarg;
    va_start(myarg, format);
    int i, count_char = 0;

    for (i = 0; format[i] != '\0'; i++)
    {
        if (format[i] != '%')
        {
            my_putchar(format[i]);
            count_char++;
        }
        else
        {
            i++;
            if (format[i] == 'c')
                check_char(myarg, &count_char);

            else if (format[i] == 's')
                check_string(myarg, &count_char);

            else if (format[i] == '%')
                check_percent(&count_char);

        }
    }

    va_end(myarg);
    return (count_char);
}


// this function stress test my code
int main()
{
    int ret;

    // testing the %c specifier
    ret = _printf("%c\n", 'a');
    printf("Characters printed: %d\n", ret); // expected output: 2

    // testing the %s specifier
    ret = _printf("%s\n", "Hello, world!");
    printf("Characters printed: %d\n", ret); // expected output: 14

    // testing the %% specifier
    ret = _printf("100%%\n");
    printf("Characters printed: %d\n", ret); // expected output: 5

    _printf("%s\n", "Hello, world!");



//-------------------


    int i;
    char *str = "Hello, world!";
    char c = 'x';

    // Test the output of a single character
    _printf("%c\n", c);

    // Test the output of a string
    _printf("%s\n", str);

    // Test the output of a percent sign
    _printf("%%\n");

    // // Test the output of multiple characters and strings
    // _printf("Testing %d %s %c %s\n", 123, "foo", 'A', "bar");

    // Test a large number of characters
    for (i = 0; i < 1000; i++) {
        _printf("%s", "x_");
    }

    return (0);
}

