#include "shell.h"

/**
 * print - printf func
 * @text:the message to be printed
 *
 * Return:None
 */
void print(const char *text)
{
        write(STDOUT_FILENO, text, strlen(text));
}
