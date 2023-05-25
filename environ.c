#include "shell.h"

char **_copyenv(void);
void free_env(void);
char **_getenv(const char *var);

/**
 * _copyenv - Creates a copy of the environment.
 *
 * Return: If an error occurs - NULL.
 *         O/w - a double pointer to the new copy.
 */
char **_copyenv(void)
{
	char **new_environ;
	size_t size;
	int indexx;

	for (size = 0; environ[size]; size++)
		;

	new_environ = malloc(sizeof(char *) * (size + 1));
	if (!new_environ)
		return (NULL);

	for (indexx = 0; environ[indexx]; indexx++)
	{
		new_environ[indexx] = malloc(_strlen(environ[indexx]) + 1);

		if (!new_environ[indexx])
		{
			for (indexx--; indexx >= 0; indexx--)
				free(new_environ[indexx]);
			free(new_environ);
			return (NULL);
		}
		_strcpy(new_environ[indexx], environ[indexx]);
	}
	new_environ[indexx] = NULL;

	return (new_environ);
}

/**
 * free_env - Frees the the environment copy.
 */
void free_env(void)
{
	int indexx;

	for (indexx = 0; environ[indexx]; indexx++)
		free(environ[indexx]);
	free(environ);
}

/**
 * _getenv - Gets an environmental variable from the PATH.
 * @var: The name of the environmental variable to get.
 *
 * Return: If the environmental variable does not exist - NULL.
 *         Otherwise - a pointer to the environmental variable.
 */
char **_getenv(const char *var)
{
	int indexx, len;

	len = _strlen(var);
	for (indexx = 0; environ[indexx]; indexx++)
	{
		if (_strncmp(var, environ[indexx], len) == 0)
			return (&environ[indexx]);
	}

	return (NULL);
}
