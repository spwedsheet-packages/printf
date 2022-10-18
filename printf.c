#include "main.h"

/**
 * printSpecifiers - prints special characters
 * @next: character after the % to identify specifier type
 * @arg: argument for the specifier
 * Return: the number of characters printed
 */

int printSpecifiers(char next, va_list arg)
{
	int typeFuncIdx;

	format_print specifiers[] = {
		{"c", print_char},
		{"s", print_string},
		{"d", print_integer},
		{"i", print_integer},
		{NULL, NULL}
	};

	for (typeFuncIdx = 0; specifiers[typeFuncIdx].identifier != NULL;
	typeFuncIdx++)
	{
		if (specifiers[typeFuncIdx].identifier[0] == next)
			return (specifiers[typeFuncIdx].printer(arg));
	}
	return (0);
}

/**
 * _printf - _printf mimics the original C printf
 * it writes output to stdout, the standard output stream
 * @format: string character of none or multiple directives
 * Return: the number of characters printed
 * return -1 for unidentified specifier error
 */

int _printf(const char *format, ...)
{
	unsigned int i;
	int identifierPrinted = 0, charPrinted = 0;
	va_list arg;

	va_start(arg, format);
	if (format == NULL)
		return (-1);
	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			_putchar(format[i]);
			charPrinted++;
			continue
		}
		if (format[i + 1] == '%')
		{
			_putchar('%');
			charPrinted++;
			i++;
			continue
		}
		if (format[i + 1] == '\0')
			return (-1);
		identifierPrinted = printSpecifiers(format[i + 1], arg);
		if (identifierPrinted == -1 || identifierPrinted != 0)
			i++;
		if (identifierPrinted > 0)
			charPrinted += identifierPrinted;

		if (identifierPrinted ==)
		{
			_putchar('%');
			charPrinted++
		}
	}
	va_end(arg);
	return (charPrinted);
}
