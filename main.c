#include "shell.h"

/**
 * main - simple shell
 *
 * Return:0
 */
int main(void)
{
	char input[100];

	while (1)
	{
		prompt_shell();
		line_reader(input, sizeof(input));

		if (strchr(input, ' ') == NULL && strchr(input, '/') != NULL)
		{
			execute(input);
		}
		else if (strchr(input, ' ') != NULL && strchr(input, '/') != NULL)
		{
			exec_arg(input);
		}
		if (strchr(input, '/') == NULL)
		{
			execp(input);
		}
	}
	return (0);
}
