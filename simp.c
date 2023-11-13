#include "shell.h"

/**
 * print - printf func
 * @text:the message to be printed
 *
 * Return:None
 */
void print(const char *text)
{
	write(STDOUT_FILENO, text, strlen(text));
}

/**
 * prompt_shell - shows the prompt when shell is active
 *
 * Return:None
 */
void prompt_shell(void)
{
	print("($) ");
}

/**
 * line_reader - reads user input
 * @input:the users input
 * @size:the size of the input
 *
 * Return:none
 */
void line_reader(char *input, size_t size)
{
	int len;

	if (fgets(input, size, stdin) != NULL)
	{
		len = strlen(input);

		if (input[len - 1] == '\n' && len > 0)
		{
			input[len - 1] = '\0';
		}
	}
}

/**
 * execute - executes cmds
 * @input:the users input cmd
 *
 * Return:None
 */
void execute(char *input)
{
	char *arg[2], *envp[] = {NULL};
	int status, p1 = fork();

		if (p1 == 0)
		{
			arg[0] = input;
			arg[1] = NULL;

			if (execve(input, arg, envp) == -1)
			{
				perror("hsh");
				exit(1);
			}
		}
		else if (p1 < 0)
		{
			perror("Fork Failed\n");
			exit(1);
		}
		else
		{
			wait(&status);
		}
}
