#ifndef PRINTF_H
#define PRINTF_H
#define JUNK(x) (void)(x)
#include <stdlib.h>
#include <stdarg.h>

typedef struct printf_parse {
	char c;
	int (*parse_func)(va_list);
 } printf_parse_t;

/**
 * printf_parser - printf parsing function
 * @c: char
 * Return: int
 */
int (*printf_parser(char c))(va_list);

/**
 * parse_char - parse char 
 * @args: va_list
 * Return: int
 */
int parse_char(va_list args);

/**
 * parse_string - parse string
 * @args: va_list
 * Return: int
 */
int parse_string(va_list args);

/**
 * parse_dec - parse decimal
 * @args: va_list
 * Return: int
 */
int parse_dec(va_list args);

/**
 * parse_int - parse int
 * @args: va_list
 * Return: int
 */
int parse_int(va_list args);

/**
 * parse_percent - parse percent
 * @args: va_list
 * Return: int
 */
int parse_percent(va_list args);

/**
 * parse_binary - parse binary
 * @args: va_list
 * Return: int
 */
int parse_binary(va_list args);

/**
 * parse_octal - parse octal
 * @args: va_list
 * Return: int
 */
int parse_octal(va_list args);

/**
 * parse_unsigned - parse unsigned
 * @args: va_list
 * Return: int
 */
int parse_unsigned(va_list args);

/**
 * parse_hex - parse hexadecimal
 * @args: va_list
 * Return: int
 */
int parse_hex(va_list args);

/**
 * parse_HEX - parse hexadecimal capital
 * @args: va_list
 * Return: int
 */
int parse_HEX(va_list args);

/**
 * _printf - print any format string
 * @format: char pointer
 * Return: int
 */
int _printf(const char *format, ...);

/**
 * _puts - print a string
 * @str: char pointer
 * Return: void
 */
void _puts(char *str);

/**
 * _putchar - print a character
 * @c: char
 * Return: void 
 */
void _putchar(char c);

#endif /* PRINTF_H */