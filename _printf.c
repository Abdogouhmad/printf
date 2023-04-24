#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>

/**
 * _printf - prints formatted output to standard output.
 *
 * @format: a string containing format specifiers that control the output.
 *          Supported format specifiers are %c, %s, and %%.
 *          Any other characters are printed as-is.
 * @...: optional arguments to be printed according to the format specifiers.
 *
 * Return: .....
 * or -1 if an error occurs.
 */


int _printf(const char *format, ...) {
    va_list args;
    va_start(args, format);
    int count = 0;
    while (*format != '\0') {
        if (*format == '%') {
            format++;
            if (*format == 'c') {
                char c = (char)va_arg(args, int);
                putchar(c);
                count++;
            }
            else if (*format == 's') {
                char *s = va_arg(args, char*);
                while (*s != '\0') {
                    putchar(*s);
                    s++;
                    count++;
                }
            }
            else if (*format == '%') {
                putchar('%');
                count++;
            }
            else {
                return -1;
            }
        }
        else {
            putchar(*format);
            count++;
        }
        format++;
    }
    va_end(args);
    return count;
}

