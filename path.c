#include "shell.h"

/**
 * execp - handles path
 * @input:the users input
 *
 * Return:None
 */
void execp(char *input)
{
	char *token[9];
	int i, status, p1;
	char *cmd;

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
	ex_it(input);
	envi_ron(input);
	cmd = token[0];
	p1 = fork();

		if (p1 == 0)
		{
			if (execvp(cmd, token) == -1)
			{
				perror("hsh using p");
				exit(1);
			}
		}
		else if (p1 < 0)
		{
			perror("fork failed");
			exit(1);
		}
		else
		{
			wait(&status);
		}
}
