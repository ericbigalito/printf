#ifndef PRINTF_H
#define PRINTF_H
#define JUNK(x) (void)(x)
#include <stdlib.h>
#include <stdarg.h>

typedef struct printf_parse {
	char c;
	int (*parse_func)(va_list);
 } printf_parse_t;

int (*printf_parser(char c))(va_list);
int parse_char(va_list args);
int parse_string(va_list args);
int parse_dec(va_list args);
int parse_int(va_list args);
int parse_percent(va_list args);
int parse_binary(va_list args);
int parse_octal(va_list args);
int parse_unsigned(va_list args);
int parse_hex(va_list args);
int parse_HEX(va_list args);

/**
 * _printf - 
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