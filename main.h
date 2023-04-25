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
/*prototypes*/
int my_putchar(char c);
int num_len(int num);
int int_to_str(int n);
void check_percent(int *count_char);
void handle_char(char c, va_list args, int *count);
int _printf(const char *format, ...);
/*advance prototypes*/
int number_to_binary(unsigned int num);
/* task 3 */
int hex_octa_binary(unsigned int num, char base);
int uint_handler(unsigned int num);


#endif
