#include "main.h"

/**
 * _path - checks if the value is in the PATH
 * @con: char previously read by the input
 * @environ: environment variable
 *
 * Return: concatenated string with the new path, con on failure
 */
char *_path(char *con, char **environ)
{
	char *val;
	char *car = "/";
	char *new_path = NULL;
	char **token = NULL;
	int compare = 1;
	int j = 0;

	val = _getenviron("PATH", environ);
	token = words(val, ":");
	while (token[j])
	{
		new_path = str_concate(token[j], car, con);
		compare = access(new_path, X_OK);
		if (compare == 0)
		{
			return (new_path);

			break;
		}
		else
		{
			free(new_path);
			j++;
		}
	}
	free(token);
	return (con);
}
