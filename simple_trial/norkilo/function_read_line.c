#include "functions.h"
/**
 * read_line - Funtion that will read the input
 * @c: This will be a flag to identify an exit
 * Return: this will be the previously read line
 */
char *read_line(ssize_t *c)
{
	char *line = NULL;
	size_t bufsize = 0;

	*c = getline(&line, &bufsize, stdin);
	return (line);
}
