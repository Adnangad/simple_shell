#include "shell.h"

/**
 * execute - executes simple shell
 * @input:users input
 *
 * Return:none
 */
void execute(char *input)
{
	char *arg[2];
	char *envp[] = {NULL};
	int status;
	int p1 = fork();

		if (p1 == 0)
		{
			arg[0] = input;
			arg[1] = NULL;

			if (execve(input, arg, envp) == -1)
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
