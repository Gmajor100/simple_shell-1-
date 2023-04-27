#include "shell.h"
/**
 * _getline - Reads an entire line from a file descriptor
 * @kon: pointer to buffer to store the line
 * @lof: pointer to size of the buffer
 * @size: file descriptor.
 * Return: length of the line or -1 on failure
 */
size_t _getline(char **kon, size_t *lof, int size)
{
	static char buff[BUFFER_SIZE];
	static size_t count, end_count;
	size_t mok = 0;
	ssize_t chg;

	if (kon == NULL || lof == NULL)
		return (-1);
	if (*kon == NULL)
	{
		*kon = malloc(BUFFER_SIZE);
		if (*kon == NULL)
			return (-1);
		*lof = BUFFER_SIZE;
	}
	while (1)
	{
		if (count >= end_count)
		{
			chg = read(size, buff, BUFFER_SIZE);
			if (chg <= 0)
				return (-1);

			count = 0;
			end_count = chg;
		}
		while (count < end_count)
		{
			if (mok >= *lof - 1)
			{
				(*kon)[mok] = '\0';
				return (mok);
			}
			(*kon)[mok++] = buff[count++];
			if ((*kon)[mok - 1] == '\n')
			{
				(*kon)[mok] = '\0';
				return (mok);
			}
		}
	}
}
