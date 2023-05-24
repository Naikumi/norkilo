#include "main.h"

/**
 * words - function tokenizes and returns the array of strings
 * @lineptr: What is previously read by the input
 * @separ: separator to tokenize from
 *
 * Return: a pointer to pointer of characters
 */
char **words(char *lineptr, char *separ)
{
	char **tokenz;
	char *word;
	int j = 0, value = 0;

	value = _strlen(lineptr);
	tokenz = malloc(sizeof(char *) * value);
	if (tokenz == NULL)
		return (NULL);
	word = strtok(lineptr, separ);
	while (word != NULL)
	{
		tokenz[j] = word;
		j++;
		word = strtok(NULL, separ);
	}
	tokenz[j] = NULL;
	return (tokenz);
}
