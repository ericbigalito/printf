#include "main.h"
#include <stdarg.h>
#include <stdio.h>

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
			for (j = 1; *(format + j) != '%'; j++)
			{
				f = printf_parser(*(format + j));
				if (f)
				{
					printedc += f(ptr);
					break;
				}
			}
			if (!f)
				_putchar('0');
			format++;
		}
		format++;
    }
	/** printf("%d\n", printedc); **/
	va_end(ptr);
	return (printedc);
}

int (*printf_parser(char c))(va_list)
{
	int i;

	printf_parse_t parse_table[] =
	{
		{'c', parse_char},
		{'s', parse_string},
		{'d', parse_dec},
		{'i', parse_int},
		{'%', parse_percent},
		{'\0', NULL}
	};

	if (!c)
		return (NULL);


	for (i = 0; parse_table[i].c != '\0'; i++)
	{
		if (parse_table[i].c == c)
			return parse_table[i].parse_func;	
	}

	return (NULL);
}