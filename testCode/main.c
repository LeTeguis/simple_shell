#include <stdio.h>
#include <stdlib.h>
#include "../shell.h"

/**
 * main - entry point
 *
 * @argc: number of parameter
 * @argv: parameter
 *
 * Return: 0
 */

int main(int __attribute__((__unused__)) argc, char __attribute__((__unused__)) **argv)
{
        char str[] = "ls /bin/ls /usr/bin/ls";
        char **result_split = 0;
        unsigned int i = 0;

        result_split = _strtok(str, " ");

        if (result_split == 0)
                printf("pas de decoupe\n");
        else
        {
                while (result_split[i])
                {
                        printf("%s > ", result_split[i]);
			_which(result_split[i]);
                        printf("***************************\n");
                        i++;
                }
		if (environ)
		{
			while (environ[i])
			{
				printf("%s\n", environ[i++]);
			}
		}
                printf("---------------------------------\n");
                _frees(result_split);
        }
        return (0);
}
