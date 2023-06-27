#include "main.h"
#include <stdarg.h>

/**
 * parse_binary - parse binary
 * @args: va_list
 * Return: int
 */
int parse_binary(va_list args)
{
    int num = va_arg(args, int);
	int i, j = 0;
	char *s;

	if (!num)
	{
		_putchar('0');
		return (1);
	}

	s = malloc(sizeof(char) * 100);

    if (!s)
        return (-1);

    while (num >= 2)
    {
        s[j++] = '0' + (num % 2);
        num /= 2;
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
 * parse_octal - parse octal
 * @args: va_list
 * Return: int
 */
int parse_octal(va_list args)
{
    unsigned int num = va_arg(args, unsigned int);
	int i, j = 0;
	char *s;

	if (!num)
	{
		_putchar('0');
		return (1);
	}

	s = malloc(sizeof(char) * 100);

    if (!s)
        return (-1);

    while (num >= 8)
    {
        s[j++] = '0' + (num % 8);
        num /= 8;
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
 * parse_unsigned - parse unsigned
 * @args: va_list
 * Return: int
 */
int parse_unsigned(va_list args)
{
    unsigned int num = va_arg(args, unsigned int);
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
 * parse_hex - parse hexadecimal
 * @args: va_list
 * Return: int
 */

int parse_hex(va_list args)
{
    unsigned int h, i, j, num, size;
    char hc;
    
    size = sizeof(num) * 2;

    j = 0;
    num = va_arg(args, unsigned int);
    for (i = 0; i < size; i++) 
    {
        h = (num >> ((size - i - 1) * 4)) & 0xf;
        hc = h < 10 ? '0' + h : 'a' + (h - 10);
        _putchar(hc);
        j++;
    }

    return (j);
}

/**
 * parse_HEX - parse hexadecimal capital
 * @args: va_list
 * Return: int
 */
int parse_HEX(va_list args)
{
    unsigned int h, i, j, num, size;
    char hc;
    
    size = sizeof(num) * 2;

    j = 0;
    num = va_arg(args, unsigned int);
    for (i = 0; i < size; i++) 
    {
        h = (num >> ((size - i - 1) * 4)) & 0xF;
        hc = h < 10 ? '0' + h : 'A' + (h - 10);
        _putchar(hc);
        j++;
    }

    return (j);
}
