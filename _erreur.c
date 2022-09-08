#include "shell.h"

/**
 * _printError - error
 *
 * @message: error lessage
 *
 * Return: nothing
 */

void _printError(char *message)
{
	if (message == 0)
		return;
	_puts(message);
}

/**
 * _procede - execute
 *
 * @arg: argument
 *
 * Return: nothing
 */

void _procede(shell_arg *arg)
{
	struct stat st;
	pid_t child_pid;
	int status;

	if (arg->argc > 1)
	{
		_printError("./shell: No such file or directory\n");
		return;
	}
	if (stat(arg->argv[0], &st) == 0)
	{
		child_pid = fork();
		if (child_pid == -1)
		{
			perror("Error:");
			return;
		}
		if (child_pid == 0)
		{
			if (execve(arg->argv[0], arg->argv, NULL) == -1)
				perror("Error:");
			return;
		}
		else
		{
			wait(&status);
			return;
		}
		if (execve(arg->argv[0], arg->argv, NULL) == -1)
			perror("Error:");
	}
	else
		_printError("./shell: No such file or directory\n");
}
