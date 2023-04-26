#include "shell.h"
/**
 *_eputs - prints an input string
 * @str: the string to be printed
 *
 * Return: Nothing
 */

void _leputs(char *str)
{
	int im = 0;

	if (!str)
		return;
	while (str[i] != '\0')
	{
		_leputchar(str[i]);
		im++;
	}
}

/**
 * _leputchar - writes the character c to stderr
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */

int _leputchar(char c)
{
	static int im;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || im >= WRITE_BUF_SIZE)
	{
		write(2, buf, im);
		im = 0;
	}
	if (c != BUF_FLUSH)
		buf[im++] = c;
	return (1);
}

/**
 * _lputfd - writes the character c to given nu
 * @c: The character to print
 * @fd: The filedescriptor to write to
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */

int _lputfd(char c, int nu)
{
	static int im;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || im >= WRITE_BUF_SIZE)
	{
		write(fd, buf, i);
		im = 0;
	}
	if (c != BUF_FLUSH)
		buf[i++] = c;
	return (1);
}

/**
 *_putsfd - prints an input string
 * @str: the string to be printed
 * @fd: the filedescriptor to write to
 *
 * Return: the number of chars put
 */

int _putsfd(char *str, int nu)
{
	int im = 0;

	if (!str)
		return (0);
	while (*str)
	{
		im += _putfd(*str++, nu);
	}
	return (im);
}
