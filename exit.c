#include "shell.h"
/**
 **_strncpy - copies a string
 *@dest: the destination string to be copied to
 *@src: the source string
 *@n: the amount of characters to be copied
 *Return: the concatenated string
 */

char *_strncpy(char *dest, char *src, int n)
{
	int i, k, m;
	char *s = dest;

	i = 0;
	k = 0;
	while (src[k] != '\0' && k < n - 1)
	{
		dest[i] = src[k];
		k++;
	}
	if (k < n)
	{
		m = k;
		while (m < n)
		{
			dest[m] = '\0';
			m++;
		}
	}
	return (s);
}

/**
 * *_strncat - concatenates two strings
 *@dest: the first string
 *@src: the second string
 *@n: the amount of bytes to be maximally used
 *Return: the concatenated string
 */

char *_strncat(char *dest, char *src, int n)
{
	int k, m;
	char *s = dest;

	k = 0;
	m = 0;
	while (dest[k] != '\0')
		k++;
	while (src[m] != '\0' && m < n)
	{
		dest[k] = src[m];
		k++;
		m++;
	}
	if (m < n)
		dest[k] = '\0';
	return (s);
}

/**
 * *_strchr - locates a character in a string
 *@s: the string to be parsed
 *@c: the character to look for
 *Return: (s) a pointer to the memory area s
 */

const char *_strchr(const char *s, char c)
{
	do {
		if (*s == c)
			return (s);
	} while (*s++ != '\0');

	return (NULL);
}
