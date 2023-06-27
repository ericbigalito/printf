#include "main.h"
#include <stdarg.h>

/**
 * parse_char - parse char
 * @args: va_list
 * Return: int
 */
int parse_char(va_list args)
{
	char c;

	c = va_arg(args, int);

	if (!c)
		return (-1);
	_putchar(c);
	return (1);
}

/**
 * parse_string - parse string
 * @args: va_list
 * Return: int
 */
int parse_string(va_list args)
{
	int i = 0;
	char *s;

	s = va_arg(args, char *);

	if (!s)
		return (-1);

	while (*s != '\0')
	{
		_putchar(*s);
		i++;
		s++;
	}
	return (i);
}

/**
 * parse_dec - parse decimal
 * @args: va_list
 * Return: int
 */
int parse_dec(va_list args)
{
	int num = va_arg(args, int);
	int i = 0, j = 0;
	char *s;

	if (!num)
	{
		_putchar('0');
		return (1);
	}

	if (num < 0)
	{
		_putchar('-');
		num = -num;
		i++;
	}

	s = malloc(sizeof(char) * 15);

	if (!s)
		return (-1);

	while (num >= 10)
	{
		s[j++] = '0' + (num % 10);
		num /= 10;
	}
	s[j] = '0' + num;
	i = j + 1;

	while (j >= 0)
	{
		_putchar(s[j--]);
	}

	free(s);
	return (i);
}

/**
 * parse_int - parse int
 * @args: va_list
 * Return: int
 */
int parse_int(va_list args)
{
	int num = va_arg(args, int);
	int i, j = 0;
	char *s;

	if (!num)
	{
		_putchar('0');
		return (1);
	}

	s = malloc(sizeof(char) * 15);

	if (!s)
		return (-1);

	while (num >= 10)
	{
		s[j++] = '0' + (num % 10);
		num /= 10;
	}
	s[j] = '0' + num;
	i = j + 1;

	while (j >= 0)
	{
		_putchar(s[j--]);
	}

	free(s);

	return (i);
}

/**
 * parse_percent - parse percent
 * @args: va_list
 * Return: int
 */
int parse_percent(va_list args)
{
	JUNK(args);
	_putchar('%');
	return (1);
}
