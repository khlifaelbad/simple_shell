#include "main.h"
/**
 * _strlen - length of the string
 * @str: the  string to count the length
 *
 * Return: length of the string
*/
int _strlen(char *str)
{
	int length = 0;

	if (str == NULL)
		return (0);
	while (str[length] != '\0')
		length++;
	return (length);
}
/**
 * _strdup - make a real copy of string
 * @line: the line to copy
 *
 * Return: string
*/
char *_strdup(char *line)
{
	char *line_cpy = NULL;
	int i;

	if (line == NULL)
		return (NULL);
	line_cpy = malloc(sizeof(char) * (_strlen(line) + 1));
	if (line_cpy == NULL)
		return (NULL);
	for (i = 0; line[i] != '\0'; i++)
		line_cpy[i] = line[i];
	line_cpy[i] = '\0';
	return (line_cpy);
}

/**
 * _strcpy - copy the string from source to destination including
 * the null (\0) byte
 * @dest: destination character array
 * @src: source character array
 *
 * Return: array of characters
 */
char *_strcpy(char *dest, char *src)
{
	char *original_dest, *original_src;

	original_dest = dest;
	original_src = src;
	for (; *original_src != '\0'; original_src++, original_dest++)
		*original_dest = *original_src;
	*original_dest = '\0';
	return (dest);
}
/**
 * _strc - concatenate two strings
 * @dest: destination string
 * @src: source string
 *
 * Return: result of concatenation
 */
char *_strc(char *dest, char *src)
{
	char *dest_clone, *src_clone;

	dest_clone = dest, src_clone = src;
	for (; *dest_clone != '\0'; dest_clone++)
		;
	for (; *src_clone != '\0'; src_clone++, dest_clone++)
	{
		*dest_clone = *src_clone;
	}
	*dest_clone = '\0';
	return (dest);
}

