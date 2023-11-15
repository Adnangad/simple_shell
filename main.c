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
		if (strchr(input, ' ') == NULL)
		{
			execute(input);
		}
		else
		{
			exec_arg(input);
		}
		if (strchr(input, '/') == NULL)
		{
			execp(input);
		}
	}
	free(input);
	return (0);
}
