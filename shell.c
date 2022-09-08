#include "shell.h"

/**
 * main - entry point
 *
 * Description: Simple sheel
 *
 * Return: 0
 */

int main(void)
{
	int exit = 0;

	while (!exit)
	{
		char *line = 0;
		size_t n = 0;
		ssize_t erreur = 0;
		char *first = 0;
		shell_arg *arg = 0;

		_puts("$ ");
		erreur = _getline(&line, &n);
		if (line == 0 || erreur == -1)
			continue;
		arg = _strtok(line, " ");
		if (arg == 0)
			continue;
		_procede(arg);
		/* if (_strcmp(line, "exit") == 0)i */
			/* exit = 1; */
		free(line);
		line = 0;
		if (first != 0)
			free(first);
		first = 0;
		if (arg != 0)
			_freearg(arg);
		arg = 0;
	}
	return (0);
}
