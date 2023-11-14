#include "shell.h"

/**
 * ex_it - exits the shell
 * @input:the users input
 * 
 * Return:none
 */
void ex_it(char *input)
{
	if (strcmp(input, "exit") == 0)
	{
		exit(0);
	}
}
