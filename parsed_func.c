#include "main.h"

/**
 * parsed_func - a function that receives the string to be printed
 * from the _printf function
 *
 * @format: contains list of all characters to be printed
 * @specifier_list: a list of all the format specifiers
 * @argument_list: a list containing all the arguments parsed
 *
 * Return: total number of characters printed
 */
int parsed_func(const char *format, convert_t specifier_list[],
		va_list argument_list)
{
	int i, j, r_val, printed_chars;

	printed_chars = 0;

	for (i = 0; format[i] != '\0'; i++) /* iterate through the main string */
	{
		if (format[i] == '%') /* checks for format specifier */
		{
			/* iterate through the struct to find the right specifier function */
			for (j = 0; specifier_list[j].symbol != NULL; j++)
			{
				if (format[i + 1] == specifier_list[j].symbol[0])
				{
					r_val = specifier_list[j].specifier_func(argument_list);
					if (r_val == -1)
						return (-1);
					printed_chars += r_val;
					break;
				}
			}
			if (specifier_list[j].symbol == NULL && format[i + 1] != ' ')
			{
				if (format[i + 1] != '\0')
				{
					writer_func(format[i]);
					writer_func(format[i + 1]);
					printed_chars += 2;
				}
				else
					return (-1);
			}
			i += 1; /* updating i to skip format symbols */
		}
		else
		{
			writer_func(format[i]);
			printed_chars++;
		}
	}
	return (printed_chars);
}
