#include "shell.h"
void *_realloc(void *pointr, unsigned int old_size, unsigned int new_size);
void assign_lineptr(char **linepointr, size_t *n, char *buffer, size_t b);
ssize_t _getline(char **linepointr, size_t *n, FILE *stream);

/**
* _realloc - Reallocates a memory block using malloc and free.
* @ptr: A pointer to the memory previously allocated.
* @old_size: The size in bytes of the allocated space for ptr.
* @new_size: The size in bytes for the new memory block.
*
* return: If new_size == old_size - ptr.
*         If new_size == 0 and ptr is not NULL - NULL.
*         Otherwise - a pointer to the reallocated memory block.
*/
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
void *mem;
char *pointr_copy, *filler;
unsigned int indexx;
if (new_size == old_size)
return (pointr);
if (pointr == NULL)
{
mem = malloc(new_size);
if (mem == NULL)
return (NULL);
return (mem);
}
if (new_size == 0 && pointr != NULL)
{
free(pointr);
return (NULL);
}
pointr_copy = pointr;
mem = malloc(sizeof(*pointr_copy) * new_size);
if (mem == NULL)
{
free(pointr);
return (NULL);
}
filler = mem;
for (indexx = 0; indexx < old_size && indexx < new_size; indexx++)
filler[indexx] = *pointr_copy++;
free(pointr);
return (mem);
}
/**
* assign_lineptr - Reassigns the lineptr variable for _getline.
* @lineptr: A buffer to store an input string.
* @n: The size of lineptr.
* @buffer: The string to assign to lineptr.
* @b: The size of buffer.
*/
void assign_linepointr(char **linepointr, size_t *n, char *buffer, size_t b)
{
if (*linepointr == NULL)
{
if (b > 120)
*n = b;
else
*n = 120;
*linepointr  = buffer;
}
else if (*n < b)
{
if (b > 120)
*n = b;
else
*n = 120;
*linepointr = buffer;
}
else
{
_strcpy(*linepointr, buffer);
free(buffer);
}
}
/**
* _getline - Reads input from a stream.
* @lineptr: A buffer to store the input.
* @n: The size of lineptr.
* @stream: The stream to read from.
*
* Return: The number of bytes read.
*/
ssize_t _getline(char **linepointr, size_t *n, FILE *stream)
{
static ssize_t input;
ssize_t ret;
char c = 'x', *buffer;
int r;
if (input == 0)
fflush(stream);
else
return (-1);
input = 0;
buffer = malloc(sizeof(char) * 120);
if (!buffer)
return (-1);
while (c != '\n')
{
r = read(STDIN_FILENO, &c, 1);
if (r == -1 || (r == 0 && input == 0))
{
free(buffer);
return (-1);
}
if (r == 0 && input != 0)
{
input++;
break;
}
if (input >= 120)
buffer = _realloc(buffer, input, input + 1);
buffer[input] = c;
input++;
}
buffer[input] = '\0';
assign_linepointr(linepointr, n, buffer, input);
ret = input;
if (r != 0)
input = 0;
return (ret);
}
