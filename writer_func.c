#include "main.h"

/**
 * writer_func - a function that prints character to stdout
 *
 * @c: the character to be printed
 *
 * Return: the printed characters
 */

int writer_func(char c)
{
	return (write(1, &c, 1));
}
