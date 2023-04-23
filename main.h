#ifndef MAIN_H
#define MAIN_H
/*by div-styl and adilma53*/
/*definers*/
#define MAX_DIGITS 10
/* 0_task headers */
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>
/* 0_task prototypes */
int my_strlen(const char *str);
int my_putchar(const char c);
void print_string(const char *string);
void check_char(va_list myarg, int *count_char);
void check_string(va_list myarg, int *count_char);
void check_percent(int *count_char);
int _printf(const char *format, ...);
/* 1_task prototypes */
void num_to_string(int *count_char, int num);
void switches(char c, va_list myarg, int *counter);
#endif
