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
		execute(input);
	}
	return (0);
}
