#include "shell.h"

/**
 * read_input - Reads input from the user.
 * @input: Buffer to store the user input.
 */
void read_input(char *input)
{
    printf("#cisfun$ ");
    if (fgets(input, MAX_INPUT_LENGTH, stdin) != NULL)
    {
        int len = strlen(input);
        if (input[len - 1] == '\n' && len > 0)
        {
            input[len - 1] = '\0';
        }
    }
}

/**
 * tokenize_input - Tokenizes the input string.
 * @input: Input string to be tokenized.
 * @token: Array to store the tokens.
 */
void tokenize_input(char *input, char *token[MAX_TOKENS])
{
	int i;
    token[0] = strtok(input, " ");
    for (i = 1; i < MAX_TOKENS; i++)
    {
        token[i] = strtok(NULL, " ");
        if (token[i] == NULL)
        {
            break;
        }
    }
    token[MAX_TOKENS - 1] = NULL;
}

/**
 * execute_command_simple - Executes a command without arguments.
 * @token: Array of tokens representing the command.
 * Return: Status of the executed command.
 */
int execute_command_simple(char *token[])
{
    int p1, status;

    p1 = fork();

    if (p1 == 0)
    {
        execvp(token[0], token);
        perror("Failed to execute using execvp\n");
        exit(EXIT_FAILURE);
    }
    else if (p1 < 0)
    {
        perror("Failed to fork\n");
    }
    else
    {
        wait(&status);
    }

    return status;
}

/**
 * execute_command_with_arguments - Executes a command with arguments.
 * @token: Array of tokens representing the command.
 * Return: Status of the executed command.
 */
int execute_command_with_arguments(char *token[])
{
    int p1, status;

    p1 = fork();

    if (p1 == 0)
    {
        execvp(token[0], token);
        perror("Failed to execute using execvp\n");
        exit(EXIT_FAILURE);
    }
    else if (p1 < 0)
    {
        perror("Failed to fork\n");
    }
    else
    {
        wait(&status);
    }

    return status;
}

/**
 * execute_command_with_path - Executes a command with path.
 * @token: Array of tokens representing the command.
 * @envp: Array of environment variables.
 * Return: Status of the executed command.
 */
int execute_command_with_path(char *token[], char *envp[])
{
    int p1, status;

    p1 = fork();

    if (p1 == 0)
    {
        if (execve(token[0], token, envp) == -1)
        {
            perror("Failed to execute using execve\n");
            exit(EXIT_FAILURE);
        }
    }
    else if (p1 < 0)
    {
        perror("Failed to fork\n");
    }
    else
    {
        wait(&status);
    }

    return status;
}
