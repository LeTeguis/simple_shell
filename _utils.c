#include "shell.h"

/**
 * _strlen - get len
 *
 * @str: string
 *
 * Description: get the length of str
 *
 * Return: lenght
 */

unsigned int _strlen(char *str)
{
	unsigned int i = 0;
	
	while (str[i])
		i++;
	return (i);
}

/**
 * _strcmp - compare
 *
 * @str1: first string
 * @str2: second string
 *
 * Description: compare str1 and str2
 *
 * Return: 1 is equal and 0 if not
 */

int _strcmp(char *str1, char *str2)
{
	unsigned int i = 0;

	if (str1 == 0 && str2 == 0)
		return (1);
	if (str1 == 0 || str2 == 0)
		return (0);
	while (1)
	{
		if (str1[i] != str2[i])
			return (0);
		if (!str1[i] && str2[i])
			return (0);
		if (str1[i] && !str2[i])
			return (0);
		if (!str1[i] && !str2[i])
			return (1);
		i++;
	}
}

/**
 * _strcpy - copy
 *
 * @str: source of string
 * @all: copy entirly string if all greater or equal than 0
 * @start: begint copy index
 * @end: end copy index
 *
 * Description: copy str if end < start the copi is inverse
 *
 * Return: destination of copy
 */

char *_strcpy(char *str, int all, unsigned int start, unsigned int end)
{
	unsigned int leng = (end < start) ? (start - end + 1) : (end - start + 1);
	char *result = 0;
	unsigned int i = 0;
	unsigned int j = 0;
	unsigned int len_str = _strlen(str);

	if (str == 0 || start >= len_str || end >= len_str)
		return (0);
	if (all < 0)
	{
		end = len_str - 1;
		start = 0;
		if (end < start)
		{
			end = 0;
			start = len_str - 1;
		}
		leng = len_str;
	}
	result = (char *)malloc(sizeof(char) * (leng + 1));
	if (!result)
		return (0);
	if (end < start)
	{
		for (i = start; i >= end; i--)
			result[j++] = str[i];
	}
	else if (end > start)
	{
		for (i = start; i <= end; i++)
			result[j++] = str[i];
	}
	else
		result[0] = str[start];
	result[leng] = '\0';
	return (result);
}
