#include "shell.h"
/**
 * main - Entry point for the simple shell.
 * Return: Always 0.
 */
int main(int argc, char *argv[])
{
    char *input = NULL;
    char *token[MAX_TOKENS];
    char *envp[] = {NULL};
    ssize_t len;

    if (argc > 1)
    {
        FILE *file = fopen(argv[1], "r");
        if (!file)
        {
            perror("Error opening file\n");
            exit(EXIT_FAILURE);
        }

        while ((len = getline(&input, NULL, file)) != -1)
        {
            if (len > 0 && input[len - 1] == '\n')
            {
                input[len - 1] = '\0';
                len--;
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

        fclose(file);
    }
    else
    {
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
    }

    free(input);

    return 0;
}
