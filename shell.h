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

void prompt_shell(void);
void print(const char *text);
void line_reader(char *input, size_t size);
void execute(char *input);
void exec_arg(char *input);
void execp(char *input);
void ex_it(char *input);
void envi_ron(char *input);
int _printf(const char *format, ...);
int putstr(char *str);
void printc(char c);

#endif
