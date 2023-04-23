#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>

#define MAX_DIGITS 10

int my_strlen(const char *str);
int my_putchar(char c);
void print_string(const char *string);
void check_char(va_list myarg, int *count_char);
void check_string(va_list myarg, int *count_char);
void check_percent(int *count_char);
void num_to_string(int *count_char, int num);
void switches(char c, va_list myarg, int *counter);
int _printf(const char *format, ...);

#endif