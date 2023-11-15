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

/**
 * prompt_shell - shows the prompt when shell is active
 *
 * Return:None
 */
void prompt_shell(void)
{
	print("#cisfun$ ");
	fflush(stdout);
}

/**
 * line_reader - reads user input
 * @input:the users input
 * @size:the size of the input
 *
 * Return:none
 */
void line_reader(char *input, size_t size)
{
	int len;

	if (fgets(input, size, stdin) != NULL)
	{
		len = strlen(input);

		if (input[len - 1] == '\n' && len > 0)
		{
			input[len - 1] = '\0';
		}
	}
}
