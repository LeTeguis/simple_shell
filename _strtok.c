#include "shell.h"

/**
 * _nextDelim - get
 *
 * @str: string
 * @del: string
 * @debut: ui
 *
 * Description:
 *
 * Return: size of text
 */
int _nextDelim(char *str, char *del, unsigned int debut)
{
	unsigned int len_del = _strlen(del);
	int i = 0;

	if (str == 0 || !str[debut + i])
		return (-1);
	if (del == 0 || len_del == 0)
		return (-2);
	while (str[debut + i])
	{
		if (del[0] == str[debut + i])
		{
			unsigned int j = 0;

			while (del[j])
			{
				if (!str[debut + i + j] || del[j] != str[debut + i + j])
					break;
				j++;
			}
			if (j == len_del)
				return (i);
		}
		i++;
	}
	return (i == 0 ? -1 : i);
}

/**
 * _extractto - get
 *
 * @str: string
 * @begin: ui
 * @taille: size
 *
 * Description:
 *
 * Return: string extract
 */

char *_extractto(char *str, unsigned int begin, unsigned int taille)
{
	char *extract = 0;
	unsigned int len_str = _strlen(str);
	unsigned int i = 0;

	if (str == 0 || begin >= len_str || (begin + taille - 1) >= len_str)
		return (0);
	extract = (char *)malloc(sizeof(char) * (taille + 1));
	if (extract == 0)
		return (0);
	for (i = 0; i < taille; i++)
		extract[i] = str[begin + i];
	extract[taille] = '\0';
	return (extract);
}

/**
 * _freearg - get
 *
 * @arg: argument
 *
 * Description: free
 *
 * Return: nothing
 */

void _freearg(shell_arg *arg)
{
	int i = 0;

	if (arg == 0)
		return;
	arg->argc = 0;
	if (arg->argv == 0)
	{
		free(arg);
		return;
	}
	while (arg->argv[i])
		free(arg->argv[i++]);
	arg->argv = 0;
	free(arg);
}

/**
 * _recaparg - get
 *
 * @arg: argument
 * @str: string
 * @d: ui
 * @t: i
 * @ld: ui
 *
 * Description:
 *
 * Return: error
 */

int _recaparg(shell_arg *arg, char *str, unsigned int *d,
		int t, unsigned int ld)
{
	char **tmp = 0;

	if (arg == 0 || str == 0 || d == 0)
		return (-1);
	if (t == 0)
	{
		(*d)++;
		return (2);
	}
	if (arg->argc > 0)
		tmp = (char **)realloc(arg->argv, sizeof(char *) * (arg->argc + 2));
	else
		tmp = (char **)malloc(sizeof(char *) * 2);
	if (tmp == 0)
	{
		_freearg(arg);
		return (-1);
	}
	arg->argv = tmp;
	arg->argv[arg->argc] = _extractto(str, *d, t);
	if (arg->argv[arg->argc] == 0)
	{
		_freearg(arg);
		return (-1);
	}
	arg->argc++;
	*d = *d + t + ld;
	if (*d >= _strlen(str))
		return (1);
	return (0);
}

/**
 * shell_arg - split
 *
 * @str: string
 * @delim: string
 *
 * Description: split str wit delim
 *
 * Return: arg
 */

shell_arg *_strtok(char *str, char *delim)
{
	shell_arg *arg = 0;
	int next_ = 0;
	unsigned int debut = 0;
	unsigned int lendel = _strlen(delim);

	if (str == 0)
		return (0);
	arg = (shell_arg *)malloc(sizeof(shell_arg));
	if (arg == 0)
		return (0);
	arg->argc = 0;
	arg->argv = 0;
	while (next_ >= 0)
	{
		next_ = _nextDelim(str, delim, debut);
		if (next_ != -1)
		{
			int s = _recaparg(arg, str, &debut, next_, lendel);

			if (s == 2)
				continue;
			if (s == -1)
				return (0);
			if (s == 1)
				break;
		}
	}
	if (arg->argc == 0)
		return (0);
	arg->argv[arg->argc] = 0;
	return (arg);
}
