#include "main.h"

/**
 * _getenviron - function gets the path from an environment
 * @name: The name from the environment
 * @environ: takes the environment
 *
 * Return: a character with the path
 */
char *_getenviron(char *name, char **environ)
{
	char **tokenizado;
	int j = 0;

	j = 0;
	while (environ[j] != NULL)
	{
		tokenizado = words(*(environ + j), "=");
			if (_strcmp(tokenizado[0], name) == 0)
			{
				break;
			}
		free(tokenizado);
		j++;
	}
	return (tokenizado[1]);
}
