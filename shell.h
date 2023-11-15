#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdarg.h>
#define MAX_TOKENS 8
#define MAX_INPUT_LENGTH 100
void read_input(char *input);
void tokenize_input(char *input, char *token[MAX_TOKENS]);
int execute_command_simple(char *token[]);
int execute_command_with_arguments(char *token[]);
int execute_command_with_path(char *token[], char *envp[]);
#endif
