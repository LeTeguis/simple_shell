#include "shell.h"

char *_which(char *file)
{
	struct stat st;

	if (stat(file, &st) == 0)
	{
		printf(" FOUND\n");
	}
	else
	{
		printf(" NOT FOUND\n");
	}
	return (0);
}
