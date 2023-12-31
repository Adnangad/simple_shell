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
	char *envp[] = {NULL};
	char *arg[2];
	int p1 = fork();

	if (strchr(input, ' ') == NULL)
	{
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
	else
	{
		exec_arg(input);
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

	p2 = fork();

	if (p2 == 0)
	{
		execve(token[0], token, envp);
		print("Command not found");
		exit(1);
	}
	else if (p2 < 0)
	{
		perror("Failed to fork");
		exit(1);
	}
	else
	{
		wait(&status);
	}
}

/**
 * execp - shell that handles path
 * @input:users input
 *
 * Return:none
 */
void execp(char *input)
{
	char *token[10];
	int i, status, p3;

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

	p3 = fork();

	if (p3 == 0)
	{
		if (execvp(token[0], token) == -1)
		{
			perror("failed to execvp");
		}
	}
	else if (p3 < 0)
	{
		perror("failed to fork p3");
		exit(1);
	}
	else
	{
		wait(&status);
	}
}
