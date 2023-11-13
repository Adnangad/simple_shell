#include "shell.h"

/**
 * exec_arg - adds args to cmds
 * @input:users input cmd
 *
 * Return:None
 */
void exec_arg(char *input)
{
	char *token[9];
	int i, p2, status;
	char *envp[] = {NULL};

	token[0] = strtok(input, " ");

	for (i = 1; i < 8; i++)
	{
		token[i] = strtok(NULL, " ");

		if (token[i] == NULL)
		{
			break;
		}
	}
	token[i] = NULL;

	p2 = fork();

	if (p2 == 0)
	{
		if (execve(token[0], token, envp) == -1)
		{
			perror("hsh");
		}
	}
	else if (p2 < 0)
	{
		perror("failed to fork");
		exit(1);
	}
	else
	{
		wait(&status);
	}
}
