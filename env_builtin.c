#include "shell.h"

/**
 * shell_setenv_builtin - setenv builtin.
 * @argc: numbers of string in a array.
 * @argv: an array of string.
 *
 * Return: 0 and 1 if error.
 */
int shell_setenv_builtin(int argc, char **argv)
{
	if (argc != 3)
	{
		perror("setenv: Invalid number of arguments");
		return (1);
	}
	if (setenv(argv[1], argv[2], 1) != 0)
	{
		perror("setenv: unable to set environment variable");
		return (1);
	}
	return (0);
}

/**
 * shell_unsetenv_builtin - unsetenv builtin.
 * @argc: numbers of strings in an array.
 * @argv: an array of strings.
 *
 * Return: 0 and 1 if error.
 */
int shell_unsetenv_builtin(int argc, char **argv)
{
	if (argc != 2)
	{
		perror("unsetenv: Invalid number of arguments");
		return (1);
	}
	if (unsetenv(argv[1]) != 0)
	{
		perror("unsetenv: unable to unset environment Variable");
		return (1);
	}
	return (0);
}
