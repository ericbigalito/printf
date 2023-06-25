#include "main.h"

void printBuffer(char buffer[], int *buffIndex);

/**
 * myPrintf - Custom printf function
 * @format: Format string
 * Return: Number of printed characters
 */
int myPrintf(const char *format, ...)
{
    int i, printed = 0, printedChars = 0;
    int flags, width, precision, size, buffIndex = 0;
    va_list args;
    char buffer[BUFF_SIZE];

    if (format == NULL)
        return -1;

    va_start(args, format);

    for (i = 0; format && format[i] != '\0'; i++)
    {
        if (format[i] != '%')
        {
            buffer[buffIndex++] = format[i];
            if (buffIndex == BUFF_SIZE)
            {
                printBuffer(buffer, &buffIndex);
            }
            printedChars++;
        }
        else
        {
            printBuffer(buffer, &buffIndex);
            flags = getFlags(format, &i);
            width = getWidth(format, &i, args);
            precision = getPrecision(format, &i, args);
            size = getSize(format, &i);
            ++i;
            printed = handlePrint(format, &i, args, buffer, flags, width, precision, size);
            if (printed == -1)
            {
                va_end(args);
                return -1;
            }
            printedChars += printed;
        }
    }

    printBuffer(buffer, &buffIndex);

    va_end(args);

    return printedChars;
}

/**
 * printBuffer - Prints the contents of the buffer if it exists
 * @buffer: Array of characters
 * @buffIndex: Index at which to add the next character, represents the length
 */
void printBuffer(char buffer[], int *buffIndex)
{
    if (*buffIndex > 0)
    {
        write(1, &buffer[0], *buffIndex);
    }

    *buffIndex = 0;
}

