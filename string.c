#include "shell.h"

/**
 * _strcmp - compares two strings.
 * @str1: first string.
 * @str2: second string.
 *
 * Return: result of the two string.
 */
int _strcmp(char *str1, char *str2)
{
	int pen = 0, end_result;

	while (*(str1 + pen) == *(str2 + pen) && *(str1 + pen) != '\0')
		pen++;

	end_result = (*(str1 + pen) - *(str2 + pen));

	return (end_result);
}

/**
 * _strdup - duplicate a string.
 * @string: string to be duplicated.
 *
 * Return: a pointer.
 */
char *_strdup(char *string)
{
	char *pen;
	int w, lenght;

	if (string == NULL)
	{
		return (NULL);
	}

	lenght = _strlen(string);

	pen = malloc(sizeof(char) * (lenght + 1));
	if (!pen)
		return (NULL);
	for (w = 0; *string != '\0'; string++, w++)
	{
		pen[w] = string[0];
	}
	pen[w++] = '\0';

	return (pen);
}

/**
 * _strlen - returns lenght of string.
 * @str: string.
 *
 * Return: int.
 */
int _strlen(char *str)
{
	int num = 0;

	while (*str != '\0')
	{
		num++;
		str++;
	}
	return (num);
}

/**
 * _strchr - search for character in a string.
 * @str: string to checked.
 * @ch: character.
 *
 * Return: pointer or NULL if not seen.
 */
const char *_strchr(const char *str, char ch)
{
	while (*str)
	{
		if (*str == ch)
		{
			return (str);
		}
		str++;
	}
	if (!ch)
	{
		return (str);
	}
	return (NULL);
}



