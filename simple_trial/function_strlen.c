#include "functions.h"
/**
* _strlen - This will count the number of characters from a string
* @s: Parameter
* Return: Will return the number of char
*/
int _strlen(char *s)
{
	char *a = s;

	while (*a)
	{
	++a;
	}
return (a - s);
}
