#include "shell.h"

/**
 * _strcpy - copies strings.
 * @dest: destination.
 * @src: source string.
 *
 * Return: a pointer to dest.
 */
char *_strcpy(char *dest, const char *src)
{
	char *tm = dest;

	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
	return (lf);
}

/**
 * _strcat - concatenate two string.
 * @dest: destination.
 * @src: source string.
 *
 * Return: a pointer to dest.
 */
char *_strcat(char *dest, const char *src)
{
	char *lf = dest;

	while (*dest != '\0')
	{
		dest++;
	}
	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
	return (lf);
}

