#include "main.h"

/**
 * _strcmp - function compares two strings
 * @str1: first string to compare
 * @str2: second string to compare
 *
 * Return: 0 if both are the same, a number on failure
 */
int _strcmp(char *str1, char *str2)
{
	int j = 0;

	while ((str1[j] != '\0' && str2[j] != '\0') && str1[j] == str2[j])
	{
		j++;
	}
	return (str1[j] - str2[j]);
}
