#include "functions.h"
/**
 * str_concat - This will concatenate three strings
 * @s1: First string
 * @s2: Second string
 * @s3: Third string
 * Return: a pointer or NULL
 */
char *str_concat(char *s1, char *s2, char *s3)
{
	int i, j, k;
	int tam1 = 0, tam2 = 0, tam3 = 0;
	char *dest;

	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";
	if (s3 == NULL)
		s3 = "";
	tam1 = _strlen(s1);
	tam2 = _strlen(s2);
	tam3 = _strlen(s3);

	dest = malloc((tam1 + tam2 + tam3 + 1));

	if (dest == NULL)
	{
		free(dest);
		return (NULL);
	}
	else
	{
		for (i = 0; i < tam1; i++)
		{
			dest[i] = s1[i];
		}
		for (j = 0; j < tam2; j++)
		{
			dest[i + j] = s2[j];
		}
		for (k = 0; k <= tam3; k++)
		{
			dest[i + j + k] = s3[k];
		}
	}
	return (dest);
}
