#include "main.h"
#include <stdarg.h>

/**
 * _printf - print anything
 * @format: const char pointer
 *
 * Return: int
 */
int _printf(const char *format, ...)
{
	int (*f)(va_list), j, printedc = 0;
	va_list ptr;

	if (!format)
		return (-1);

	va_start(ptr, format);
	while (*format != '\0')
	{
		if (*format != '%')
		{
			_putchar(*format);
			printedc++;
		}
		else
		{
			for (j = 1; *(format + j) != '\0'; j++)
			{
				f = printf_parser(*(format + j));
				if (f)
				{
					printedc += f(ptr);
					break;
				}
			}
			if (!f)
			{
				_putchar('%');
				_putchar(*(format + 1));
				printedc += 2;
			}
			format++;
		}
		format++;
	}
	/** printf("%d\n", printedc); **/
	va_end(ptr);
	return (printedc);
}

/**
 * printf_parser - parse printf string
 * @c: char
 * Return: int
 */
int (*printf_parser(char c))(va_list)
{
	int i;

	printf_parse_t parse_table[] = {
		{'c', parse_char}, {'s', parse_string},
		{'d', parse_dec}, {'i', parse_int},
		{'%', parse_percent}, {'b', parse_binary},
		{'o', parse_octal}, {'u', parse_unsigned},
		{'x', parse_hex}, {'X', parse_HEX},
		{'\0', NULL}
	};

	if (!c)
		return (NULL);


	for (i = 0; parse_table[i].c != '\0'; i++)
	{
		if (parse_table[i].c == c)
			return (parse_table[i].parse_func);
	}

	return (NULL);
}
