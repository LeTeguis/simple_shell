#ifndef H_SHELL_H
#define H_SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <stdint.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>

#if !(defined SSIZE_MAX)
#define SSIZE_MAX (SIZE_MAX >> 1)
#endif

/**
 * struct shell_arg - get argument int sheel
 *
 * @argc: number of argument
 * @argv: all argument
 *
 * Description: define the argument
 */

struct shell_arg
{
	char **argv;
	int argc;
};

typedef struct shell_arg shell_arg;

/* armgument */
void _freearg(shell_arg *arg);
shell_arg *_strtok(char *str, char *delim);
int _nextDelim(char *str, char *del, unsigned int debut);
char *_extractto(char *str, unsigned int begin, unsigned int taille);
/* input output */
void _puts(char *str);
ssize_t _getline(char **linestr, size_t *n);

/* utils */
unsigned int _strlen(char *str);
int _strcmp(char *s1, char *s2);

/* erreur */
void _printError(char *message);

/* execute */
void _procede(shell_arg *arg);
#endif
