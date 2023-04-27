#include "shell.h"
/**
 * main - start of function.
 * @argc: numbers of command.
 * @argv: array of strings.
 *
 * Return: always 0 (SUCCESS).
 */
int main(int argc, char **argv)
{
	char *prompt, *input, *command;
	int status = EXIT_SUCCESS;

	prompt = "simple_shell$ ";
	while (1)
	{
		_print_prompt(prompt);
		input = _read_input();
		if (_strlen(input) == 0)
		{
			continue;
		}
		argc = _parse_input(input, argv);
		command = argv[0];
		if (_strcmp(command, "exit") == 0)
		{
			if (argc > 1)
			{
				status = atoi(argv[1]);
			}
			free(input);
			exit(status);
		}
		if (_strcmp(command, "env") == 0)
		{
			env_builtin(environ);
			continue;
		}
		if (_strcmp(command, "setenv") == 0)
		{
			shell_setenv_builtin(argc, argv);
			continue;
		}
		if (_strcmp(command, "unsetenv") == 0)
		{
			shell_setenv_builtin(argc, argv);
			continue;
		}
		_execute_command(command, argv);
		free(input);
	}
	return (0);
}
