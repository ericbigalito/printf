#include "main.h"
#include <unistd.h>

void _puts(char *str)
{
    int len;

    for(len = 0; str[len] != '\0'; len++);

    write(1, str, len);
}

void _putchar(char c)
{
    write(1, &c, 1);
}