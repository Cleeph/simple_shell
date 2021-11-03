#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <limits.h>
#include <signal.h>

typedef struct variables
{
	char **arguments;
	char *buffer;
	char **env;
	size_t count;
	char **argv;
	int status;
	char **commands;
} variables_t;

typedef struct builtins
{
	char *name;
	void (*function)(variables_t *);
} builtin_t;

char **_realloc(char **ptr, size_t *size);
unsigned int check_match(char c, const char *str);
char *_strtok(char *str, const char *delim);
void (*is_builtin(variables_t *vbles))(variables_t *vbles);
void new_cd(variables_t *vbles);
void new_exit(variables_t *vbles);
void new_env(variables_t *vbles);
int _atoi(char *str);
char **read_env(char **env);
void free_env(char **env);
void print_error(variables_t *vbles, char *msg);
void _puts2(char *str);
char *_uitoa(unsigned int count);
int check_for_dir(char *str);
char *find_path(char **env);
int execute_cwd(variables_t *vbles);
void check_for_path(variables_t *vbles);
int path_execute(char *command, variables_t *vbles);
char **split_line(char *buffer, char *delimiter);
int _strcmpr(char *strcmp1, char *strcmp2);
char *_strdup(char *strtodup);
char *_strcat(char *strc1, char *strc2);
ssize_t _puts(char *str);
unsigned int _strlen(char *str);
ssize_t getline(char **lineptr, size_t *n, FILE *stream);
#endif
