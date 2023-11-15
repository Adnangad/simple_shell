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
		execute(input);
		
	}
	return (0);
}
