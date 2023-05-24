#include "functions.h"
/**
 * l_path - Function to check if the value is in the PATH
 * @cont: The char previously read by the input
 * @env: The environ
 * Return: A concatenated string with the new path or cont if it fails
 */
char *l_path(char *cont, char **env)
{
	char *value;
	char *car = "/";
	char *newpath = NULL;
	char **token = NULL;
	int compare = 1;
	int i = 0;

	value = _getenv("PATH", env);
	token = words(value, ":");
	while (token[i])
	{
		newpath = str_concat(token[i], car, cont);
		compare = access(newpath, X_OK);
		if (compare == 0)
		{
			return (newpath);
			/*free(newpath);*/
			break;
		}
		else
		{
			free(newpath);
			i++;
		}
	}
	free(token);
	return (cont);
}
