#include "shell.h"

/**
 * main - executes shell
 *
 *
 * Return:none
 */
int main(void)
{
	char input[100];

	while (1)
	{
		prompt_shell();
		line_reader(input, sizeof(input));
		if (strcmp(input, "exit") == 0)
		{
			break;
		}
		if (strchr(input, '/') != NULL)
		{
			execute(input);
		}
		else
		{
			execp(input);
		}
	}
	return (0);
}
