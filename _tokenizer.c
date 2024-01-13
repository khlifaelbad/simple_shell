#include "main.h"
#define DELIM " \n\t"
/**
 * _tokenizer - parse the string
 * @line: the line to parse
 *
 * Return: return table of commands
*/
char **_tokenizer(char *line)
{
	char *line_cpy = NULL, *token = NULL, **command = NULL;
	int length = 0, i;

	if (line == NULL)
		return (NULL);
	line_cpy = _strdup(line);
	token = strtok(line_cpy, DELIM);
	if (token == NULL)
	{
		free(line_cpy), line_cpy = NULL;
		free(line), line = NULL;
		return (NULL);
	}
	while (token)
	{
		length++;
		token = strtok(NULL, DELIM);
	}
	free(line_cpy), line_cpy = NULL;
	command = malloc(sizeof(char *) * (length + 1));
	if (command == NULL)
	{
		free(line), line = NULL;
		return (NULL);
	}
	token  = strtok(line, DELIM);
	i = 0;
	while (token)
	{
		command[i++] = _strdup(token);
		token = strtok(NULL, DELIM);
	}
	command[i] = NULL;
	free(line);
	return (command);
}

