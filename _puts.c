#include "main.h"
#include <unistd.h>

/**
 * _puts - print a string
 * @str: char pointer
 * Return: void
 */
void _puts(char *str)
{
	int len;

	for (len = 0; str[len] != '\0'; len++)
		;

	write(1, str, len);
}

/**
 * _putchar - print a character
 * @c: char
 * Return: void
 */
void _putchar(char c)
{
	write(1, &c, 1);
}
