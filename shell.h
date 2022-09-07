#ifndef H_SHELL_H
#define H_SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
#include <stdint.h>
#include <unistd.h>

#if !(defined SSIZE_MAX)
#define SSIZE_MAX (SIZE_MAX >> 1)
#endif

/**
 * sheel_arg - shell argument
 *
 * @argv: liste of argument plus name of programme
 * terminate by null value
 * @argc: number of argument plus 1
 *
 * Description: represent the liste of argument is passed
 * int simple shell program
 */

typedef struct shell_arg shell_arg;
struct shell_arg
{
	char **argv;
	int argc;
};

typedef struct list_s list_s;
struct list_s
{
	char *str;
	struct list_s *next;
};

extern char *var_shell_line;
extern shell_arg *var_shell_arg;
extern char **environ;

/* String utils */
char *_strcpy(char *str, int all, unsigned int start, unsigned int end);
int _strcmp(char *str1, char *str2);
unsigned int _strlen(char *str);

/* input output and split */
void _puts(char *str);
char **_strtok(char *str, char *del);
size_t _getline(char **linestr, size_t *n, FILE *file);
void _frees(char **str);

int replacec(char *str, const char c1, const char c2);
int prompt();

/* shell */
void freeShellArg(shell_arg *arg);
shell_arg* addShellArg(shell_arg *arg, char *lineptr);
char *_which(char *file);

/* Event */
char *_getevent(const char *name);
void _printdir(const char path);
int _setenv(const char *name, const char *value, int overwrite);
int _unsetenv(const char *name);

/* list_s */
list_s creatlist_s(char *value);
void freelist_s(list_s *list);

#endif
