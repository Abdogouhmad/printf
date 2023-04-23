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
<<<<<<< HEAD

/* 0_task prototypes */
=======
/*definers*/
#define MAX_DIGITS 10
/*prototypes*/
>>>>>>> a5ddaf89e94b6be1e35a9f16032da5363aaec997
int my_strlen(const char *str);
int my_putchar(char c);
void print_string(const char *string);
void check_char(va_list myarg, int *count_char);
void check_string(va_list myarg, int *count_char);
void check_percent(int *count_char);
void num_to_string(int *count_char, int num);
void switches(char c, va_list myarg, int *counter);
int _printf(const char *format, ...);
<<<<<<< HEAD
/* 1_task prototypes */
void int_handler(int num, int *count_char);
int switches(char casevalue, va_list myarg, int *counter);

=======
>>>>>>> a5ddaf89e94b6be1e35a9f16032da5363aaec997
#endif
