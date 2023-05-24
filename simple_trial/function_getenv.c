#include "functions.h"
/**
 * _getenv - function that will get the path from a env
 * @name: This will be the name from the env like "PATH"
 * @env: This will take the environ
 * Return: a char * with the path
 */
char *_getenv(char *name, char **env)
{
	char **tokenizado;
	int i = 0;

	i = 0;
	while (env[i] != NULL)
	{
		tokenizado = words(*(env + i), "=");
			if (_strcmp(tokenizado[0], name) == 0)
			{
				break;
			}
		free(tokenizado);
		i++;
	}
	return (tokenizado[1]);
}
