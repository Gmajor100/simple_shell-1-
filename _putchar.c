#include "shell.h"

/**
 * _putchar - writes the character to stdout
 * @c: The character to print.
 *
 * Description: write characters to stdout.
 * Return: On success 1.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _putstr - prints out string.
 * @str: sting to be print.
 *
 * Description: printing out strings
 * Return: int.
 */
int _putstr(char *str)
{
	int length;
	int v;

	length = _strlen(str);

	for (v = 0; v < length; v++)
	{
		_putchar(str[v]);
	}

	return (length);
}
