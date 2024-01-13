#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

extern char **environ;

char *_getline(void);
char **_tokenizer(char *line);
char *_getpath(char *cmd);
int execute(char **command, char **av, int index);
void error_print(char **av, char *cmd, int index);
int is_builtins(char **av, int ac, char **command, int *index, int *status);
void handle_builtins(char **av, int ac, char **cmd, int *index, int *status);
void _print_env(char **command, int *status);
void print_exit_error(char **av, int *index, char **command);
void exit_builtin(char **av, int ac, char **command, int *status, int *index);

int _strlen(char *str);
char *_strdup(char *line);
int _strncmp(char *str1, char *str2, int n);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
int _atoi(char *s);
char *_itoa(int n);
int _strcmp(char *str1, char *str2);
int is_number(char *str);

void free2d(char **command);

#endif





