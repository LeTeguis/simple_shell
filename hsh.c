#include "shell.h"

/**
 * main - entry point
 *
 * Description: creation the simple shell
 *
 * Return: 0
 */

int main(void)
{
	int status;

	while (1)
	{
		pid_t child_pid;

		child_pid = fork();
		if (child_pid == -1)
		{
			perror("Error:");
			return (1);
		}
		if (child_pid == 0)
		{
			prompt();
			if (var_shell_line != 0)
				free(var_shell_line);
			if (var_shell_arg != 0)
				freeShellArg(var_shell_arg);
			return (0);
		}
		else
		{
			wait(&status);
		}
	}
	if (var_shell_line != 0)
		free(var_shell_line);
	if (var_shell_arg != 0)
		freeShellArg(var_shell_arg);
	return (0);
}
