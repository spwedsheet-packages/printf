#include "main.h"

/**
 * _printf - a function that produces output according to a format
 *
 * @format: a character string.
 *
 * Return: the number of characters printed excluding the terminating null byte
 */

int _printf(const char *format, ...)
{
	int printed_chars;

	/* a structure that list the specifiers */
	convert_t specifier_list[] = {
		{"c", print_char},
		{"s", print_string},
		{"%", print_percent},
		{"d", print_integer},
		{"i", print_integer},
		{NULL, NULL}
	};

	va_list argument_list;

	if (format == NULL)
	{
		return (-1);
	}

	va_start(argument_list, format);

	/* calling the parsed function */
	printed_chars = parsed_func(format, specifier_list, argument_list);
	va_end(argument_list);
	return (printed_chars);
}
