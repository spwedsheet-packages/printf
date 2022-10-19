#ifndef _PRINTF_H_
#define _PRINTF_H_

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * struct convert - a structure for specifier symbols and functions
 *
 * @symbol: the specifier symbol
 * @specifier_func: the corresponding function to the specifief symbol
 */
typedef struct convert
{
	char *symbol;
	int (*specifier_func)(va_list);
}convert_t;

/* main functions */
int _printf(const char *format, ...);
int writer_func(char c);
int parsed_func(const char *format, convert_t specifier_list[],
		va_list argument_list);

/* specifier functions */
int print_char(va_list);
int print_string(va_list);
int print_percent(va_list);
int print_integer(va_list);

#endif /* _PRINTF_H_ */
