#include "main.h"

/**
 * free2d - free 2 dimentional array
 * @command: array of arguments
 *
 * Return: nothing
*/
void free2d(char **command)
{
	int i;

	if (command == NULL)
		return;
	for (i = 0; command[i] != NULL; i++)
		free(command[i]), command[i] = NULL;
	free(command), command = NULL;
}
/**
 * _strncmp - determine if the two strings are equile
 * @str1: first string
 * @str2: second string
 * @n: length to see
 *
 * Return: 0 is equal of 1 if not
*/
int _strncmp(char *str1, char *str2, int n)
{
	if (str1 == NULL || str2 == NULL)
		return (-1);
	while (n > 0)
	{
		if (*str1 != *str2 || *str1 == '\0' || *str2 == '\0')
			return (*str1 - *str2);
		str1++;
		str2++;
		n--;
	}
	return (0);
}
/**
 * _strcmp - compare two values
 * @str1: string 1
 * @str2: string 2
 *
 * Return: 0 if equal or n if not
*/
int _strcmp(char *str1, char *str2)
{
	while (*str1 != '\0' && *str2 != '\0' && (*str1 == *str2))
	{
		str1++;
		str2++;
	}
	return (*str1 - *str2);
}
/**
 * _getenv - get env value
 * @name: name of the envirement variable
 *
 * Return: pointer to the value or NULL
*/
char *_getenv(char *name)
{
	int length, i;

	if (name == NULL)
		return (NULL);
	length = _strlen(name);
	for (i = 0; environ[i] != NULL; i++)
	{
		if (strncmp(name, environ[i], length) == 0 && environ[i][length] == '=')
			return (_strdup(&environ[i][length + 1]));
	}
	return (NULL);
}
/**
 * _getpath - get the right path
 * @cmd: command we want to test
 *
 * Return: path or NULL
*/
char *_getpath(char *cmd)
{
	char *token = NULL, *env = NULL, *path = NULL;
	struct stat st;
	int i;

	if (cmd == NULL)
		return (NULL);
	for (i = 0; cmd[i] != '\0'; i++)
	{
		if (cmd[i] == '/')
		{
			if (stat(cmd, &st) == 0)
				return (_strdup(cmd));
			return (NULL);
		}
	}
	env = _getenv("PATH");
	if (env == NULL)
		return (NULL);
	token = strtok(env, ":");
	while (token)
	{
		path = malloc(sizeof(char) * (_strlen(token) + _strlen(cmd) + 2));
		if (path == NULL)
		{
			free(env), env = NULL;
			return (NULL);
		}
		_strcpy(path, token);
		_strcat(path, "/");
		_strcat(path, cmd);
		if (stat(path, &st) == 0)
		{
			free(env), env = NULL;
			return (path);
		}
		token = strtok(NULL, ":");
		free(path), path = NULL;
	}
	free(env), env = NULL;
	return (NULL);
}
}


