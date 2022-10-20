#include "main.h"

/**
 * print_char - a function that prints char data types
 *
 * @ap: characters to be printed
 *
 * Return: an integer value of 1
 */
int print_char(va_list ap)
{
	writer_func(va_arg(ap, int));
	return (1);
}

/**
 * print_string - a function that prints stringg data types
 *
 * @ap: list of strings tro be printed
 *
 * Return: the number of characters printed
 */
int print_string(va_list ap)
{
	int i;
	char *str;

	str = va_arg(ap, char *);

	if (str == NULL)
	{
		str = "(null)";
	}

	for (i = 0; str[i] != '\0'; i++)
	{
		writer_func(str[i]);
	}
	return (i);
}

/**
 * print_percent - a function that prints percent sign
 *
 * @ap: list of characters provided
 *
 * Return: the number of signs printed
 */
int print_percent(__attribute__((unused)) va_list ap)
{
	writer_func('%');
	return (1);
}

/**
 * print_integer - a function that prints integer data types
 *
 * @ap: list of characters to be printed
 *
 * Return: total number of characters printed
 */
int print_integer(va_list ap)
{
	unsigned int num;
	int r_val, i, j;

	i = va_arg(ap, int);
	j = 1;
	r_val = 0;

	if (i < 0)
	{
		r_val += writer_func('-');
		num = i * -1;
	}
	else
	{
		num = i;
	}

	for (; num / j > 9; )
	{
		j *= 10;
	}

	for (; j != 0; )
	{
		r_val += writer_func((num / j) + '0');
		num %= j;
		j /= 10;
	}
	return (r_val);
}
