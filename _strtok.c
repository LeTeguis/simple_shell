#include "shell.h"

/**
 * _frees - free
 *
 * @arraystr: multiple table string
 *
 * Description: destroy in memory arraystr
 *
 * Return: nothing
 */

void _frees(char **arraystr)
{
	unsigned int i = 0;

	if (arraystr == 0)
		return;
	while (arraystr[i])
		free(arraystr[i++]);
	free(arraystr);
}

/**
 * newadd - add
 *
 * @arraystr: the multitable array to string
 * @size: actual leng of arrystr
 * @str: new value to add in arraystr
 *
 * Description: add str in size position of arraystr
 *
 * Return: new arraysstr or null
 */

char **newadd(char **arraystr, unsigned int *size, char *str)
{
	char **result = 0;

	if (size == 0)
	{
		_frees(arraystr);
		return (0);
	}
	if (arraystr == 0)
		result = (char **)malloc(sizeof(char *) * ((*size) + 1));
	else
		result = (char **)realloc(arraystr, sizeof(char *) * ((*size) + 1));
	if (result == 0)
	{
		_frees(arraystr);
		return (0);
	}
	result[*size] = str;
	*size = *size + 1;
	return (result);
}

/**
 * positionadd - got to
 *
 * @str: string wit got to next position
 * @del: delimiter string
 * @debut: begin index
 * @fin: end index
 *
 * Description: got to begin of next del
 *
 * Return: the number of char go or -1 to error
 */

int positionadd(char *str, char *del, unsigned int *debut, unsigned int *fin)
{
	int j = 0;

	if (str == 0 || debut == 0 || fin == 0 || del == 0)
		return (-1);
	while (del[j] && str[*fin + j])
	{
		if (del[j] != str[*fin + j])
		{
			if (!str[*fin + j])
				return (j);
			return (-1);
		}
		j++;
		if (!del[j])
		{
			if (*fin != *debut)
				return (j);
			else
			{
				*debut = *fin + j;
				*fin = *debut - 1;
				return (-1);
			}
		}
	}
	*debut = *fin + j;
	*fin = *debut - 1;
	return (-1);
}

/**
 * _strtok - spleat
 *
 * @str: string wi wont to split
 * @del: delimiter
 *
 * Description: split the str wit delimiter
 *
 * Return: all split str wit result or NULL
 */

char **_strtok(char *str, char *del)
{
	char **result = 0;
	unsigned int i = 0;
	unsigned int k = 0;
	unsigned int nbr = 0;
	unsigned int len_del = _strlen(del);
	unsigned int len_str = _strlen(str);
	
	if (str == 0)
		return (0);
	if (del == 0 || len_del == 0 || len_str < len_del)
	{
		char *copy = _strcpy(str, 0, 0, len_str - 1);

		if (copy != 0)
			result = newadd(result, &nbr, copy);
		if (copy == 0 || result == 0)
			return (0);
		return (result);
	}
	while (str[i])
	{
		int add = positionadd(str, del, &k, &i);

		if (add >= 0)
		{
			char *copy = _strcpy(str, 0, k, i - 1);

			if (copy != 0)
				result = newadd(result, &nbr, copy);
			if (copy == 0 || result == 0)
			{
				_frees(result);
				return (0);
			}
			k = i + add;
			i = k - 1;
		}
		i++;
		if (!str[i] && k <= len_str - 1)
		{
			char *copy = _strcpy(str, 0, k, len_str - 1);

			if (copy != 0)
				result = newadd(result, &nbr, copy);
			if (copy == 0 || result == 0)
			{
				_frees(result);
				return (0);
			}
			result = newadd(result, &nbr, 0);
			return (result);
		}
	}
	return (result);
}
