#include "shell.h"

/**
 * my_strtok - tokenizes a string
 * @str: the string to tokenize
 * @delim: the delimiter to use
 *
 * Return: a pointer to the next token or NULL if there are no more tokens
 */
char *my_strtok(char *str, const char *delim)
{
	static char *joshua;
	char *modern;

	if (str == NULL && joshua == NULL)
	{
		return (NULL);
	}

	if (str != NULL)
	{
		joshua = str;
	}
	modern = joshua;

	while (*joshua != '\0')
	{
		if (_strchr(delim, *joshua) != NULL)
		{
			*joshua = '\0';
			joshua++;
			return (modern);
		}
		joshua++;
	}

	if (*modern != '\0')
	{
		return (modern);
	}
	joshua = NULL;
	return (NULL);
}
