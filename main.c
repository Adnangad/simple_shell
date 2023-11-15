#include "shell.h"
/**
 * main - Entry point for the simple shell.
 * Return: Always 0.
 */
int main(void)
{
    char *input = NULL;
    char *token[MAX_TOKENS];
    char *envp[] = {NULL};
    ssize_t len;

    while (1)
    {
        len = read_input(&input);

        if (len == -1)
        {
            break;
        }

        if (strcmp(input, "exit") == 0)
        {
            break;
        }

        tokenize_input(input, token);

        if (token[1] != NULL)
        {
            execute_command_with_arguments(token);
        }
        else
        {
            if (strchr(token[0], '/') == NULL)
            {
                execute_command_simple(token);
            }
            else
            {
                execute_command_with_path(token, envp);
            }
        }
    }

    free(input);

    return 0;
}
