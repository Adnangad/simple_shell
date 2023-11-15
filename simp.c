#include "shell.h"

/**
 * execute - executes simple shell
 * @input:users input
 *
 * Return:none
 */
void execute(char *input)
{
	int status;
	int p1 = fork();

		if (p1 == 0)
		{
			if (execlp(input, input, (char *)NULL) == -1)
			{
				perror("Failed to execute");
				exit(EXIT_FAILURE);
			}
		}
		if (p1 < 0)
		{
			perror("failed to fork");
			exit(1);
		}
		else
		{
			wait(&status);
		}
}

/**
 * exec_arg - simple shell + args
 * @input:users input
 *
 *
 * Return:none
 */
void exec_arg(char *input)
{
	char *token[10];
	int i, status, p2;
	char *envp[] = {NULL};

	token[0] = strtok(input, " ");

	for (i = 1; i < 9; i++)
	{
		token[i] = strtok(NULL, " ");

		if (token[i] == NULL)
		{
			break;
		}
	}
	token[i] = NULL;

	if (strchr(input, ' ') != NULL)
	{
		p2 = fork();

		if (p2 == 0)
		{
			if (execve(token[0], token, envp) == -1)
			{
				perror("Failed to execute cmd");
			}
		}
		else if (p2 < 0)
		{
			perror("Failed to fork");
		}
		else
		{
			wait(&status);
		}
	}
}
