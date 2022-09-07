#include "shell.h"

char *var_shell_line = 0;
shell_arg *var_shell_arg = 0;

/**
 * freeSheeArg - free arg
 *
 * @arg: argument shell_arg
 *
 * Description: free in memory arg
 *
 * Return: nothing
 */

void freeShellArg(shell_arg *arg)
{
	if (arg != 0)
	{
		if (arg->argc > 0)
		{
			int i = 0;
			
			while (i < arg->argc)
				free(arg->argv[i++]);
			free(arg->argv);
		}
		free(arg);
	}
}

/**
 * addShellArg - add arg
 *
 * @lineptr: string to content argument
 * @arg: shell struct argument
 *
 * Description: split lineptr to space word and get all
 * word
 *
 * Return: shell_arg find or NULL
 */

shell_arg* addShellArg(shell_arg *arg, char *lineptr)
{
	char **param = 0;
	char **param1 = 0;
	int i = 0;

	if (arg == 0)
	{
		arg = (shell_arg *)malloc(sizeof(shell_arg));
		if (arg == 0)
			return (0);
		arg->argc = 0;
	}
	if (lineptr == 0)
	{
		if (arg->argc == 0)
			param1 = (char **)malloc(sizeof(char *));
		else
			param1 = (char **)realloc(arg->argv, sizeof(char *) * (arg->argc + 1));
		if (param1 == 0)
			return (0);
		arg->argv = param1;
                arg->argv[arg->argc] = 0;
		return (arg);
	}
	param = _strtok(lineptr, " ");
        if (param == 0)
                return (0);
	while (param[i])
	{
		if (arg->argc == 0)
			param1 = (char **)malloc(sizeof(char *));
		else
			param1 = (char **)realloc(arg->argv, sizeof(char *) * (arg->argc + 1));
		if (param1 == 0)
			return (0);
		arg->argv = param1;
		arg->argv[arg->argc] = param[i];
		arg->argc++;
		i++;
        }
	return (arg);
}

/**
 * getShellArg - get arg
 *
 * @lineptr: string to get argument
 *
 * Description: split lineptr to space word and get all
 * word
 *
 * Return: shell_arg find or NULL
 */

shell_arg* getShellArg(char *lineptr, char *first)
{
	shell_arg *arg;
	char **param = 0;
	
	arg = (shell_arg *)malloc(sizeof(shell_arg));
	if (arg == 0)
		return (0);
	arg->argc = 0;
	if (first != 0)
	{
		char *copy = _strcpy(first, -1, 0, 0);
		arg->argv = (char **)malloc(sizeof(char *));

		if (copy != 0 && arg->argv != 0)
		{
			arg->argv[0] = copy;
			arg->argc++;
		}
		else
		{
			freeShellArg(arg);
			return (0);
		}
	}
	param = _strtok(lineptr, " ");
	if (param == 0)
	{
		freeShellArg(arg);
		return (0);
	}
	while (param[arg->argc])
	{	
		if (arg->argc == 0)
			arg->argv = (char **)malloc(sizeof(char *));
		else
			arg->argv = (char **)realloc(arg->argv, sizeof(char *) * (arg->argc + 1));
		if (arg->argv == 0)
		{
			freeShellArg(arg);
			return (0);
		}
		arg->argv[arg->argc] = param[arg->argc];
		arg->argc++;
	}
	arg->argv = (char **)realloc(arg->argv, sizeof(char *) * (arg->argc + 1));
	if (arg->argv == 0)
		return (0);
	arg->argv[arg->argc] = 0;
	return (arg);
}
