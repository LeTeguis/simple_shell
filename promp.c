#include "shell.h"

/**
 * replacec - move & set
 *
 * @str: string based
 * @c1: char one
 * @c2: char 2
 *
 * Description: replace in str, c1 to c2
 *
 * Return: 1 if success or 0
 */

int replacec(char *str, const char c1, const char c2)
{
	unsigned int i = 0;
	int rep = 0;

	while (str[i])
	{
		if (str[i] == c1)
		{
			rep = 1;
			str[i] = c2;
		}
		i++;
		if (!str[i] && rep == 1)
			return (1);
	}
	return (0);
}

/**
 * prompt - begin sheel
 *
 * Description: base of sheel
 *
 * Return: 1 if the funtion dont have the error 0 or not
 */

int prompt()
{
	size_t n = 0;
	char betty_style[] = "/usr/local/bin/betty-style";
	char betty_doc[] = "/usr/local/bin/betty-doc";

	if (var_shell_line != 0)
	{
		free(var_shell_line);
		var_shell_line = 0;
	}
	if (var_shell_arg != 0)
	{
		freeShellArg(var_shell_arg);
		var_shell_arg = 0;
	}
	_puts("$ ");
	_getline(&var_shell_line, &n, stdin);
	if (var_shell_line != 0)
	{
		char **param = 0;

		replacec(var_shell_line, '\n', '\0');
		param = _strtok(var_shell_line, " ");
		if (param != 0)
		{
			if (_strcmp(param[0], "betty-style") == 1)
				var_shell_arg = addShellArg(var_shell_arg, betty_style);
			else if (_strcmp(param[0], "betty-doc") == 1)
				var_shell_arg = addShellArg(var_shell_arg, betty_doc);
			else
			{
				int i = 0;

				while (param[i])
					free(param[i++]);
				free(param);
			}
			var_shell_arg = addShellArg(var_shell_arg, param[1]);
			if (param[1] != 0)
				var_shell_arg = addShellArg(var_shell_arg, 0);
		}
		/* var_shell_arg = addShellArg(var_shell_arg, var_shell_line); */
		/* var_shell_arg = addShellArg(var_shell_arg, 0); */
		if (var_shell_arg != 0 && var_shell_arg->argc == 2)
		{
			if (_strcmp(var_shell_arg->argv[0], betty_style) == 1 ||
					_strcmp(var_shell_arg->argv[0], betty_doc) == 1)
			{
				if (execve(var_shell_arg->argv[0], var_shell_arg->argv, NULL) == -1)
					perror("Error:");
			}
			else
				_puts("Usage 1: betty-style exemple.c\nor\nUsage: betty-doc exemple.c\n");
		}
		else
		{
			 _puts("Usage 2: betty-style exemple.c\nor\nUsage: betty-doc exemple.c\n");
		}
	}
	else
	{
		_puts("null\n");
		return (0);
	}
	return (1);
}
