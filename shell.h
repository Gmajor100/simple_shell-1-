#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <ctype.h>
#include "shell.h"
#include <stddef.h>

extern char **environ;

/* BUFFER_SIZE */
#define BUFFER_SIZE 1024

/* MAX_ARGV */

#define MAX_ARGV 10

/* function header */
void _print_prompt(char *prompt);
void exit(int status);
char *_read_input();
int _parse_input(char *input, char **argv);
char *_find_command(char *command);
void _execute_command(char *command, char **argv);
char *my_strtok(char *str, const char *delim);

/* print function */
int _putchar(char c);
int _putstr(char *str);

/* getline function */
size_t _getline(char **dbl, size_t *boff, int size);

/* setenv function */
char *getenv(const char *name);
int env_builtin(char **env);
int shell_unsetenv_builtin(int argc, char **argv);
int shell_setenv_builtin(int argc, char **argv);

/* string functiom */
char *_strcat(char *dest, const char *src);
char *_strcpy(char *dest, const char *src);
size_t strlen(const char *str);
int _strlen(char *str);
char *my_strtok(char *str, const char *delim);
const char *_strchr(const char *str, char ch);
char *_strdup(char *string);
int _strcmp(char *str1, char *str2);
#endif

