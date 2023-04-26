#include "shell.h"
/**
 * _print_prompt - prints prompt.
 * @prompt: shell prompt.
 *
 * Return: no return.
 */
void _print_prompt(char *prompt)
{
	write(STDOUT_FILENO, prompt, _strlen(prompt));
}

/**
 * _read_input - reads user input.
 *
 * Desciption: reads user inputs.
 * Return: pointer.
 */
char *_read_input()
{
	char *input = NULL;
	size_t lenght = 0;
	ssize_t fl_lenght;

	fl_lenght = _getline(&input, &lenght, fileno(stdin));
	if (fl_lenght == -1)
	{
		write(STDOUT_FILENO, "Terminating shell...\n", 21);
		exit(-1);
	}
	input[fl_lenght - 1] = '\0';
	return (input);
}

/**
 * _parse_input - tokensise input.
 * @input: user input.
 * @argv: array of string.
 *
 * Return: an int.
 */
int _parse_input(char *input, char **argv)
{
	int kon = 0;
	char *tok, *new_line = " \t\n";

	tok = my_strtok(input, new_line);

	while (tok != NULL && cnt < MAX_ARGV)
	{
		argv[kon] = tok;
		cnt++;
		tok = my_strtok(NULL, new_line);
	}
	argv[kon] = NULL;

	if (kon == 0)
	{
		perror("unable to tokenize user input.\n");
		exit(-1);
	}
	return (kon);
}
/**
 * _find_command - find users command.
 * @command: command to be found.
 * Return: a pointer.
 */
char *_find_command(char *command)
{
	char *ola, *ola_cpy, *dir, *cmd_ola = NULL, *al_ola;

	if (access(command, X_OK) == 0)
		return (_strdup(command));

	ola = getenv("PATH");
	ola_cpy = _strdup(ola);
	dir = my_strtok(ola_cpy, ":");
	while (dir != NULL && cmd_ola == NULL)
	{
		al_ola = malloc(_strlen(dir) + _strlen(command) + 2);
		if (al_ola == NULL)
		{
			perror("Error: failed to allocate memory");
			exit(-1);
		}
		_strcpy(al_ola, dir);
		_strcat(al_ola, "/");
		_strcat(al_ola, command);
		if (access(al_ola, X_OK) == 0)
			cmd_ola = _strdup(al_ola);
		free(al_ola);
		dir = my_strtok(NULL, ":");
	}
	if (cmd_ola == NULL)
	{
		al_ola = malloc(_strlen("/bin/") + _strlen(command) + 2);
		if (al_ola == NULL)
		{
			perror("Error: failed to allocate memory.");
			exit(-1);
		}
		_strcpy(al_ola, "/bin/");
		_strcat(al_ola, command);
		if (access(al_ola, X_OK) == 0)
			cmd_ola = _strdup(al_ola);
		free(al_ola);
	}
	free(ola_cpy);
	return (cmd_ola);
}

/**
 * _execute_command - execute a command.
 * @command: command to be executed.
 * @argv: array of strings.
 *
 * Return: no return.
 */
void _execute_command(char *command, char **argv)
{
	char *cmd_pat;
	int status, w;
	pid_t cat;

	cmd_pat = _find_command(command);
	if (cmd_pat == NULL)
	{
		perror("Command not found:");
		return;
	}
	dove = fork();

	if (dove == -1)
	{
		perror("fork() failed");
		exit(-1);
	}
	else if (dove == 0)
	{
		if (execve(cmd_ola, argv, environ) == -1)
		{
			perror("execve() failed");
			exit(-1);
		}
	}
	else
	{
		do {
			z = waitpid(dove, &status, WUNTRACED | WCONTINUED);
			if (z == -1)
			{
				perror("waitpid() failed");
				exit(-1);
			}
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
	free(cmd_ola);
}
