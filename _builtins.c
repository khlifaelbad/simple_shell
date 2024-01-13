#include "main.h"

/**
 * is_builtins - check if build in or not
 * @command: command table
 * @index: index of the line in case of wrong command
 * @av: argument table
 * @status: status
 * @ac: argument count
 *
 * Return: 1 is builtin or 0 if not
*/
int is_builtins(char **av, int ac, char **command, int *index, int *status)
{
	char *builtins[] = {"exit", "env", NULL};
	int i;
	(void)av;
	(void)status;
	(void)index;
	(void)ac;

	for (i = 0; builtins[i] != NULL; i++)
	{
		if (_strcmp(builtins[i], command[0]) == 0)
		{
			return (1);
		}
	}
	return (0);
}

/**
 * handle_builtins - check if build in or not
 * @cmd: command table
 * @index: index of the line in case of wrong command
 * @av: argument table
 * @status: status
 * @ac: argument count
 *
 * Return: 1 is builtin or 0 if not
*/
void handle_builtins(char **av, int ac, char **cmd, int *index, int *status)
{
	(void)av;
	(void)index;

	if (_strcmp(cmd[0], "exit") == 0)
	{
		exit_builtin(av, ac, cmd, status, index);
	}
	else if (_strcmp(cmd[0], "env") == 0)
		_print_env(cmd, status);
}
/**
 * _print_envir - print env content
 * @status: status
 * @command: command array
 *
 * Return: nothing
*/
void _print_envir(char **command, int *status)
{
	int i;

	for (i = 0; environ[i] != NULL; i++)
	{
		write(STDOUT_FILENO, environ[i], _strlen(environ[i]));
		write(STDOUT_FILENO, "\n", 1);
	}
	*status = 0;
	free2d(command), command = NULL;
}

/**
 * ex_builtin - exit builtin function
 * @av: argument array
 * @ac: argument count
 * @command: command array
 * @status: status
 * @index: index
 *
 * Return: nothing
*/
void ex_builtin(char **av, int ac, char **command, int *status, int *index)
{
	int length = 0, n;
	(void)ac;

	while (command[length])
		length++;
	if (length >= 2)
	{
		n = _atoi(command[1]);
		if (is_number(command[1]) && n >= 0)
		{
			*status = _atoi(command[1]) % 256;
			free2d(command), command = NULL;
			exit(*status);
		}
		else
		{
			print_exit_error(av, index, command);
			free2d(command), command = NULL;
			*status = 2;
			return;
		}
	}
	else
	{
		free2d(command);
		exit(*status);
	}
	/* free the command*/
}
/**
 * print_exit_error - print exit error
 * @av: array argument
 * @index: index
 * @command: command array
 *
 * Return: nothing
*/
void print_exit_error(char **av, int *index, char **command)
{
	char *str_index = NULL;

	str_index =  _itoa(*index);
	write(STDERR_FILENO, av[0], _strlen(av[0]));
OAOA	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, str_index, _strlen(str_index));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, command[0], _strlen(command[0]));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, "Illegal number", 14);
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, command[1], _strlen(command[1]));
	write(STDERR_FILENO, "\n", 1);
	free(str_index);

}

