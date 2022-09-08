#include "shell.h"

/**
 * _getline - get
 *
 * @linestr: string
 * @n: number of char
 *
 * Description: read the current line in file
 *
 * Return: number of char read
 */

ssize_t _getline(char **linestr, size_t *n)
{
	size_t size_read = 0;
	char buf[2];
	size_t index = *n;

	if ((linestr == 0) || (n == 0))
		return (-1);
	if (*linestr == 0)
	{
		*linestr = (char *)malloc(sizeof(char));
		if (*linestr == 0)
			return (-1);
		index = 1;
	}
	while (1)
	{
		ssize_t erreur = read(STDIN_FILENO, buf, sizeof(char));

		if (erreur == -1)
			return (-1);
		if (buf[0] == EOF || buf[0] == '\n')
			break;
		if (erreur == sizeof(char))
		{
			char *tmp = (char *)realloc(*linestr, sizeof(char) * (index + 1));

			if (tmp == 0)
				return (-1);
			*linestr = tmp;
			(*linestr)[index - 1] = (char)buf[0];
			index++;
			size_read++;
		}
	}
	*n = index - 1;
	(*linestr)[index - 1] = '\0';
	return (size_read * sizeof(char));
}

/**
 * _puts - input
 *
 * @str: string to print
 *
 * Description: print str
 *
 * Return: nothing
 */

void _puts(char *str)
{
	unsigned int length = 0;

	while (str[length])
		length++;
	write(STDOUT_FILENO, str, length);
}
