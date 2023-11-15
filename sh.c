#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
/**
 * main - creates simple shell
 *
 * Return:Always 0
 */
int main(void)
{
        char input[100];
        char *token[9];
        int len, i;
        int p1, status;
        char *envp[] = {NULL};

        while (1)
        {
                printf("#cisfun$ ");
                if (fgets(input, sizeof(input), stdin) != NULL)
                {
                        len = strlen(input);

                        if (input[len - 1] == '\n' && len > 0)
                        {
                                input[len - 1] = '\0';
                        }
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
                }
                if (strcmp(input, "exit") == 0)
                {
                        break;
                }

                p1 = fork();

                if (p1 == 0)
                {
                        if (strchr(token[0], '/') == NULL)
                        {
                                if (execvp(token[0], token))
                                {
                                        perror("Failed to execute using p\n");
                                }
                        }
                        else
                        {
                                if (execve(token[0], token, envp) == -1)
                                {
                                        perror("failed to execute using execve\n");
                                }
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
        }
        return (0);
}
