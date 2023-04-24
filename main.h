#ifndef MAIN_H
#define MAIN_H

/*by div-styl and adilma53*/
/*libraries*/
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>


/* 0_task prototypes */

/*definers*/
/* #define MAX_DIGITS 10 */
/*prototypes*/

int _strlen(const char *str);
int my_putchar(char c);
void print_string(const char *string);
void check_char(va_list myarg, int *count_char);
void check_string(va_list myarg, int *count_char);
void check_percent(int *count_char);
void handle_char(char c, va_list args, int *count,
int width, int pre);/*void switches(char c, va_list myarg, int *counter);*/
int _printf(const char *format, ...);

/* 1_task prototypes */
void int_handler(int num, int *count_char);
int switches(char casevalue, va_list myarg, int *counter);


#endif
