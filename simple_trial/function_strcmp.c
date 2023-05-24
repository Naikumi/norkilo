#include "functions.h"
/**
 * _strcmp - This will compare a two strings
 * @s1: The first string to compare
 * @s2: The second string to compare
 * Return: will return 0 if both are the same or a number if it fails
 */
int _strcmp(char *s1, char *s2)
{
	int i = 0;

	while ((s1[i] != '\0' && s2[i] != '\0') && s1[i] == s2[i])
	{
		i++;
	}
	return (s1[i] - s2[i]);
}
