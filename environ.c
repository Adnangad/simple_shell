#include "shell.h"

/**
 * envi_ron - implements the env built in
 * @input:the users input
 *
 * Return:none
 */
void envi_ron(char *input)
{
	extern char **environ;
	int p3, status;

	if (strcmp(input, "env") == 0)
	{
		p3 = fork();

		if (p3 == 0)
		{
			if (execvp("env", environ) == -1)
			{
				perror("env failed");
				exit(1);
			}
		}
		else if (p3 < 0)
		{
			perror("failed to fork for env");
			exit(1);
		}
		else
		{
			wait(&status);
		}
	}
}
