#include "main.h"
/**
 * _itoa - convert string to integer
 * @n: integer
 *
 * Return: converted integer
 */
char *_itoa(int n)
{
	char buffer[20];
	int i = 0, j, length, n_copy;
	char temp;

	if (n == 0)
		return (_strdup("0"));
	n_copy = n;
	if (n < 0)
		n *= -1;
	while (n > 0)
	{
		buffer[i++] = (n % 10) + '0';
		n /= 10;
	}
	if (n_copy < 0)
		buffer[i++] = '-';
	buffer[i] = '\0';
	length = i - 1;
	i = 0, j = length;
	while (i < j)
	{
		temp = buffer[i];
		buffer[i] = buffer[j];
		buffer[j] = temp;
		i++;
		j--;
	}
	return (_strdup(buffer));
}
/**
 * error_print - print error
 * @av: argument array
 * @cmd: wrong command
 * @index: index
 *
 * Return: nothing
*/
void error_print(char **av, char *cmd, int index)
{
	char *str_index = NULL;

	str_index =  _itoa(index);
	write(STDERR_FILENO, av[0], _strlen(av[0]));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, str_index, _strlen(str_index));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, cmd, _strlen(cmd));
	write(STDERR_FILENO, ": not found\n", 12);
	free(str_index);
}
/**
 * _atoi - convert string to integer
 * @s: string
 *
 * Return: converted integer
 */
int _atoi(char *s)
{
	int minus, plus, sign, len, multiplier, result;
	char *slen;

	minus = 0, plus = 0, len = 0, multiplier = 1, result = 0;
	while ((*s < 48 || *s > 57) && *s != '\0')
	{
		if (*s == '-')
			minus++;
		else if (*s == '+')
			plus++;
		s++;
	}
	if (*s == '\0')
	{
		result = 0;
	}
	else
	{
		sign = (minus % 2 != 0) ? -1 : 1;
		slen = s;
		while (*slen >= 48 && *slen <= 57)
		{
			len++;
			slen++;
		}
		while (len > 1)
		{
			multiplier *= 10;
			len--;
		}
		while (multiplier != 1)
		{
			result += multiplier * ((*s) - 48) * sign;
			s++;
			multiplier /= 10;
		}
		result = result + ((*s) - 48) * sign;
	}
	return (result);
}

/**
 * is_number - check string is integer
 * @str: string to check
 *
 * Return: 1 if number, 0 if not
*/
int is_number(char *str)
{
	int i;

	if (str == NULL)
		return (0);
	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] < 48 || str[i] > 57)
			return (0);
	}
	return (1);
}



